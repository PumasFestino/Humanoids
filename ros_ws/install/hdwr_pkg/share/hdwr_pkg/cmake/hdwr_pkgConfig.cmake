# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_hdwr_pkg_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED hdwr_pkg_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(hdwr_pkg_FOUND FALSE)
  elseif(NOT hdwr_pkg_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(hdwr_pkg_FOUND FALSE)
  endif()
  return()
endif()
set(_hdwr_pkg_CONFIG_INCLUDED TRUE)

# output package information
if(NOT hdwr_pkg_FIND_QUIETLY)
  message(STATUS "Found hdwr_pkg: 0.0.0 (${hdwr_pkg_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'hdwr_pkg' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${hdwr_pkg_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(hdwr_pkg_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "rosidl_cmake-extras.cmake;ament_cmake_export_include_directories-extras.cmake;ament_cmake_export_libraries-extras.cmake;ament_cmake_export_targets-extras.cmake;rosidl_cmake_export_typesupport_targets-extras.cmake;ament_cmake_export_dependencies-extras.cmake;rosidl_cmake_export_typesupport_libraries-extras.cmake")
foreach(_extra ${_extras})
  include("${hdwr_pkg_DIR}/${_extra}")
endforeach()
