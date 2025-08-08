cmake_minimum_required(VERSION 3.5)
project(task_manager)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

add_executable(push_recovery src/push_recovery.cpp)
ament_target_dependencies(push_recovery rclcpp)

install(TARGETS
  push_recovery
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()


