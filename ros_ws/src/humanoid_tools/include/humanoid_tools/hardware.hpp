#ifndef HUMANOIDTOOLS_HARDWARE_HPP
#define HUMANOIDTOOLS_HARDWARE_HPP

#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/point.hpp>
#include <rclcpp/rclcpp.hpp>

namespace HumanoidTools {

class Hardware {
public:
    Hardware();
    bool isReady() const;
    bool calibrate();
    bool navigateToKickoffPosition();
    bool isGameStarted() const;
    void approachBall(const geometry_msgs::msg::Point& ball_pos);
    void alignToGoal(const geometry_msgs::msg::Pose& goal_pose);
    void executeKick();
    bool navigateTo(const geometry_msgs::msg::Pose& target);
    void emergencyStop();

private:
    rclcpp::Logger logger_;
    bool calibrated_ = false;
    bool game_started_ = false;
    int kick_counter_ = 0;
};

} // namespace HumanoidTools

#endif
