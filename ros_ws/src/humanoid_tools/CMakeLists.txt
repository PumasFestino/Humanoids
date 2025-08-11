cmake_minimum_required(VERSION 3.8)
project(humanoid_tools)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

# Buscar dependencias
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

# Configurar biblioteca
add_library(${PROJECT_NAME}
  src/hardware.cpp
  src/vision.cpp
)

# Incluir directorios
target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

# CORRECCIÓN: Usar ament_target_dependencies para manejar las dependencias
ament_target_dependencies(${PROJECT_NAME} PUBLIC
  rclcpp
  geometry_msgs
)

# Instalación
install(
  TARGETS ${PROJECT_NAME}
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(
  DIRECTORY include/
  DESTINATION include
)

# Exportar dependencias
ament_export_include_directories(include)
ament_export_libraries(${PROJECT_NAME})
ament_export_dependencies(rclcpp geometry_msgs)

ament_package()