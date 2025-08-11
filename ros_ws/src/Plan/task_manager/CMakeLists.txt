cmake_minimum_required(VERSION 3.5)
project(task_manager)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

add_executable(striker src/striker.cpp)
ament_target_dependencies(striker rclcpp)

install(TARGETS
  striker
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()


