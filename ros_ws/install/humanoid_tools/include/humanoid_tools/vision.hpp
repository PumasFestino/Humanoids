#ifndef HUMANOIDTOOLS_VISION_HPP
#define HUMANOIDTOOLS_VISION_HPP

#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/point.hpp>
#include <rclcpp/rclcpp.hpp>
#include <random>

namespace humanoid_tools {

class Vision {
public:
    Vision(rclcpp::Logger logger);
    bool isReady() const;
    bool calibrate();
    bool isBallVisible() const;
    bool isBallKickable() const;
    bool isGoalAligned() const;
    bool isBallNear() const;
    geometry_msgs::msg::Point getBallPosition() const;
    geometry_msgs::msg::Pose getGoalPosition() const;
    void activeScanForBall();

private:
    rclcpp::Logger logger_;
    mutable bool ball_visible_ = false;
    int scan_counter_ = 0;
};

} // namespace humanoid_tools

#endif