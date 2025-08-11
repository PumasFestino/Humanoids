cmake_minimum_required(VERSION 3.8)
project(task_manager)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

# Buscar dependencias
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(humanoid_tools REQUIRED)

# Crear ejecutable
add_executable(striker_node
  src/striker.cpp
)

# CORRECCIÓN: Usar ament_target_dependencies
ament_target_dependencies(striker_node
  rclcpp
  geometry_msgs
  humanoid_tools
)

# Instalación
install(TARGETS striker_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()