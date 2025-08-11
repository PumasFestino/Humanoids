#include <rclcpp/rclcpp.hpp>
#include <humanoid_tools/hardware.hpp>
#include <humanoid_tools/vision.hpp>
#include <chrono>

enum class SMState {
    SM_SETUP,
    SM_GO_TO_KICKOFF,
    SM_WAIT_KICKOFF_SIGNAL,
    SM_SEARCH_BALL,
    SM_APPROACH_BALL,
    SM_ALIGN_TO_GOAL,
    SM_STRIKE,
    SM_RETURN_TO_POSITION,
    SM_LOST_BALL,
    SM_EMERGENCY
};

class StrikerNode : public rclcpp::Node
{
public:
    StrikerNode() : Node("striker_node"), 
                    state_(SMState::SM_SETUP),
                    ball_lost_count_(0),
                    approach_attempts_(0)
    {
        RCLCPP_INFO(this->get_logger(), "Initializing Striker State Machine");
        timer_ = this->create_wall_timer(std::chrono::milliseconds(100), 
                                        std::bind(&StrikerNode::mainLoop, this));
        
        // Initialize hardware and vision systems
        hardware_ = std::make_unique<humanoid_tools::Hardware>(this->get_logger());
        vision_ = std::make_unique<humanoid_tools::Vision>(this->get_logger());
        
        // Set striker position
        striker_position_.position.x = 1.5;
        striker_position_.position.y = 0.0;
        striker_position_.position.z = 0.0;
        striker_position_.orientation.x = 0.0;
        striker_position_.orientation.y = 0.0;
        striker_position_.orientation.z = 0.0;
        striker_position_.orientation.w = 1.0;
    }

private:
    SMState state_;
    rclcpp::TimerBase::SharedPtr timer_;
    std::unique_ptr<humanoid_tools::Hardware> hardware_;
    std::unique_ptr<humanoid_tools::Vision> vision_;
    
    int ball_lost_count_;
    int approach_attempts_;
    geometry_msgs::msg::Pose striker_position_;
    bool game_active_ = false;

    void mainLoop()
    {
        if (!hardware_ || !vision_) {
            RCLCPP_ERROR(this->get_logger(), "Hardware or vision not initialized!");
            return;
        }

        if (!hardware_->isReady() || !vision_->isReady()) {
            RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 1000, 
                                "Systems initializing...");
            return;
        }

        switch (state_) {
        case SMState::SM_SETUP:
            RCLCPP_INFO(this->get_logger(), "State: SETUP");
            if (hardware_->calibrate() && vision_->calibrate()) {
                state_ = SMState::SM_GO_TO_KICKOFF;
            }
            break;

        case SMState::SM_GO_TO_KICKOFF:
            RCLCPP_INFO(this->get_logger(), "State: GO_TO_KICKOFF");
            if (hardware_->navigateToKickoffPosition()) {
                state_ = SMState::SM_WAIT_KICKOFF_SIGNAL;
            }
            break;

        case SMState::SM_WAIT_KICKOFF_SIGNAL:
            RCLCPP_INFO_ONCE(this->get_logger(), "State: WAIT_KICKOFF_SIGNAL");
            if (hardware_->isGameStarted()) {
                game_active_ = true;
                state_ = SMState::SM_SEARCH_BALL;
            }
            break;

        case SMState::SM_SEARCH_BALL:
            RCLCPP_INFO(this->get_logger(), "State: SEARCH_BALL");
            if (vision_->isBallVisible()) {
                ball_lost_count_ = 0;
                state_ = SMState::SM_APPROACH_BALL;
            } 
            else {
                ball_lost_count_++;
                
                if (ball_lost_count_ > 30) {
                    state_ = SMState::SM_RETURN_TO_POSITION;
                } 
                else {
                    vision_->activeScanForBall();
                }
            }
            break;

        case SMState::SM_APPROACH_BALL:
            RCLCPP_INFO(this->get_logger(), "State: APPROACH_BALL");
            if (!vision_->isBallVisible()) {
                state_ = SMState::SM_LOST_BALL;
                break;
            }
            
            if (vision_->isBallKickable()) {
                approach_attempts_ = 0;
                state_ = SMState::SM_ALIGN_TO_GOAL;
            } 
            else if (approach_attempts_ > 20) {
                RCLCPP_WARN(this->get_logger(), "Approach failed - ball might be blocked");
                state_ = SMState::SM_RETURN_TO_POSITION;
            } 
            else {
                hardware_->approachBall(vision_->getBallPosition());
                approach_attempts_++;
            }
            break;

        case SMState::SM_ALIGN_TO_GOAL:
            RCLCPP_INFO(this->get_logger(), "State: ALIGN_TO_GOAL");
            if (!vision_->isBallVisible()) {
                state_ = SMState::SM_LOST_BALL;
                break;
            }
            
            if (vision_->isGoalAligned()) {
                state_ = SMState::SM_STRIKE;
            } 
            else {
                hardware_->alignToGoal(vision_->getGoalPosition());
            }
            break;

        case SMState::SM_STRIKE:
            RCLCPP_INFO(this->get_logger(), "State: STRIKE");
            hardware_->executeKick();
            state_ = SMState::SM_SEARCH_BALL;
            break;

        case SMState::SM_RETURN_TO_POSITION:
            RCLCPP_INFO(this->get_logger(), "State: RETURN_TO_POSITION");
            if (hardware_->navigateTo(striker_position_)) {
                state_ = SMState::SM_SEARCH_BALL;
            } 
            else if (vision_->isBallVisible() && vision_->isBallNear()) {
                state_ = SMState::SM_APPROACH_BALL;
            }
            break;

        case SMState::SM_LOST_BALL:
            RCLCPP_INFO(this->get_logger(), "State: LOST_BALL");
            if (vision_->isBallVisible()) {
                state_ = SMState::SM_APPROACH_BALL;
            } 
            else if (ball_lost_count_++ > 10) {
                state_ = SMState::SM_RETURN_TO_POSITION;
            }
            break;

        case SMState::SM_EMERGENCY:
            RCLCPP_ERROR(this->get_logger(), "EMERGENCY STATE ACTIVATED!");
            hardware_->emergencyStop();
            break;
        }
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<StrikerNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}