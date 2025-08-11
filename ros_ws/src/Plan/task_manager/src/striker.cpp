#include <rclcpp/rclcpp.hpp>
#include <string>
#include <vector>

enum class SMState {
    SM_SETUP,
    SM_GO_TO_KICKOFF_POSITION,
    SM_GO_TO_STRIKER_POSITION,
    SM_FIND_BALL,
    SM_GET_CLOSE_TO_BALL,
    SM_ALIGN_TO_GOAL,
    SM_STRIKE,
    SM_FINAL_STATE
};

class StrikerNode : public rclcpp::Node
{
public:
    StrikerNode() : Node("sm_stricker_node"), state_(SMState::SM_SETUP), request_(false)
    {
        RCLCPP_INFO(this->get_logger(), "Initializing State Machine Node...");
        timer_ = this->create_wall_timer(std::chrono::milliseconds(100), std::bind(&MainTrackNode::mainLoop, this));
    }

private:
    SMState state_;
    rclcpp::TimerBase::SharedPtr timer_;

    // Flag para pedir nueva instrucción
    bool request_;

    // Almacén de tokens de instrucción
    std::vector<std::string> instructionTokens_;

    void request_instruction()
    {
        instructionTokens_.clear();
        // Simulando instrucción
        instructionTokens_ = {"move", "CS", "C_Z56", "270", "platform"};
        request_ = true;

        RCLCPP_INFO(this->get_logger(), "Instruction received: %s", instructionTokens_[0].c_str());

        if (instructionTokens_[0] == "move")
        {
            state_ = SMState::SM_MOVE;
        }
        else if (instructionTokens_[0] == "retrieve")
        {
            state_ = SMState::SM_RETRIEVE;
        }
        else if (instructionTokens_[0] == "deliver")
        {
            state_ = SMState::SM_DELIVER;
        }
        else
        {
            request_ = false;
        }
    }

    void mainLoop()
    {
        switch (state_)
        {
        case SMState::SM_INIT:
            RCLCPP_INFO(this->get_logger(), "State: INIT");
            state_ = SMState::SM_WAIT_FOR_ZONES;
            break;

        case SMState::SM_WAIT_FOR_ZONES:
            RCLCPP_INFO(this->get_logger(), "State: WAIT_FOR_ZONES");
            // Aquí podrías agregar la lógica para esperar zonas
            state_ = SMState::SM_WAIT_FOR_INSTRUCTION;
            break;

        case SMState::SM_WAIT_FOR_INSTRUCTION:
            RCLCPP_INFO(this->get_logger(), "State: WAIT_FOR_INSTRUCTION");
            if (!request_)
            {
                request_instruction();
            }
            break;

        case SMState::SM_MOVE:
            RCLCPP_INFO(this->get_logger(), "State: MOVE");
            request_ = false;

            // Aquí podrías agregar navegación
            RCLCPP_INFO(this->get_logger(), "Navigating to zone: %s", instructionTokens_[2].c_str());

            state_ = SMState::SM_ALIGN;
            break;

        case SMState::SM_ALIGN:
            RCLCPP_INFO(this->get_logger(), "State: ALIGN");
            // Alineación con línea o marcador
            RCLCPP_INFO(this->get_logger(), "Aligning...");
            state_ = SMState::SM_WAIT_FOR_INSTRUCTION;
            break;

        case SMState::SM_RETRIEVE:
            RCLCPP_INFO(this->get_logger(), "State: RETRIEVE");
            request_ = false;
            // Simular grasp
            RCLCPP_INFO(this->get_logger(), "Retrieving object...");
            state_ = SMState::SM_WAIT_FOR_INSTRUCTION;
            break;

        case SMState::SM_DELIVER:
            RCLCPP_INFO(this->get_logger(), "State: DELIVER");
            request_ = false;
            // Simular drop
            RCLCPP_INFO(this->get_logger(), "Delivering object...");
            state_ = SMState::SM_WAIT_FOR_INSTRUCTION;
            break;

        case SMState::SM_FINAL_STATE:
            RCLCPP_INFO(this->get_logger(), "State: FINAL_STATE");
            // Finalizar ejecución
            rclcpp::shutdown();
            break;
        }
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MainTrackNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

