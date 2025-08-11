#include "humanoid_tools/vision.hpp"
#include <random>

namespace HumanoidTools {

Vision::Vision() : 
    logger_(rclcpp::get_logger("Vision")) {}

bool Vision::isReady() const {
    return true;
}

bool Vision::calibrate() {
    RCLCPP_INFO(logger_, "Calibrating vision system...");
    return true;
}

bool Vision::isBallVisible() const {
    // Random ball visibility (70% chance)
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::bernoulli_distribution dist(0.7);
    
    ball_visible_ = dist(gen);
    return ball_visible_;
}

bool Vision::isBallKickable() const {
    // Ball is kickable 80% of the time when visible
    return ball_visible_ && (std::rand() % 100 < 80);
}

bool Vision::isGoalAligned() const {
    // Goal is aligned 75% of the time
    return ball_visible_ && (std::rand() % 100 < 75);
}

bool Vision::isBallNear() const {
    // Ball is near 60% of the time when visible
    return ball_visible_ && (std::rand() % 100 < 60);
}

geometry_msgs::msg::Point Vision::getBallPosition() const {
    geometry_msgs::msg::Point pos;
    pos.x = 1.0 + (std::rand() % 100) / 100.0;
    pos.y = (std::rand() % 100 - 50) / 50.0;
    return pos;
}

geometry_msgs::msg::Pose Vision::getGoalPosition() const {
    geometry_msgs::msg::Pose pose;
    pose.position.x = 2.5;
    pose.position.y = (std::rand() % 100 - 50) / 100.0;
    return pose;
}

void Vision::activeScanForBall() {
    RCLCPP_INFO(logger_, "Scanning for ball [Attempt %d]", ++scan_counter_);
}

} // namespace HumanoidTools
