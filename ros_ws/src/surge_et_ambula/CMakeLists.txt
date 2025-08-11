cmake_minimum_required(VERSION 3.8)
project(surge_et_ambula)

# Buscar dependencias
find_package(ament_cmake REQUIRED)

# Instalar archivos launch
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()