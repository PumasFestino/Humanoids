#include "humanoid_tools/hardware.hpp"
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

namespace humanoid_tools {

Hardware::Hardware(rclcpp::Logger logger) : logger_(logger) {}

bool Hardware::isReady() const {
    return true;
}

bool Hardware::calibrate() {
    RCLCPP_INFO(logger_, "Calibrating motors and sensors...");
    std::this_thread::sleep_for(1s);
    calibrated_ = true;
    return true;
}

bool Hardware::navigateToKickoffPosition() {
    RCLCPP_INFO(logger_, "Moving to kickoff position");
    std::this_thread::sleep_for(500ms);
    return true;
}

bool Hardware::isGameStarted() const {
    static auto start_time = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::steady_clock::now() - start_time;
    return elapsed > 3s;
}

void Hardware::approachBall(const geometry_msgs::msg::Point& ball_pos) {
    RCLCPP_INFO(logger_, "Approaching ball at (%.2f, %.2f, %.2f)", 
                ball_pos.x, ball_pos.y, ball_pos.z);
    std::this_thread::sleep_for(300ms);
}

void Hardware::alignToGoal(const geometry_msgs::msg::Pose& goal_pose) {
    RCLCPP_INFO(logger_, "Aligning to goal at (%.2f, %.2f)", 
                goal_pose.position.x, goal_pose.position.y);
    std::this_thread::sleep_for(200ms);
}

void Hardware::executeKick() {
    RCLCPP_WARN(logger_, "EXECUTING KICK #%d!", ++kick_counter_);
    std::this_thread::sleep_for(500ms);
}

bool Hardware::navigateTo(const geometry_msgs::msg::Pose& target) {
    RCLCPP_INFO(logger_, "Navigating to (%.2f, %.2f)", 
                target.position.x, target.position.y);
    std::this_thread::sleep_for(400ms);
    return true;
}

void Hardware::emergencyStop() {
    RCLCPP_ERROR(logger_, "EMERGENCY STOP ACTIVATED!");
}

} // namespace humanoid_tools