// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hdwr_pkg:srv/HumanSrv.idl
// generated code does not contain a copyright notice

#ifndef HDWR_PKG__SRV__DETAIL__HUMAN_SRV__STRUCT_H_
#define HDWR_PKG__SRV__DETAIL__HUMAN_SRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'human_action'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/HumanSrv in the package hdwr_pkg.
typedef struct hdwr_pkg__srv__HumanSrv_Request
{
  rosidl_runtime_c__String human_action;
} hdwr_pkg__srv__HumanSrv_Request;

// Struct for a sequence of hdwr_pkg__srv__HumanSrv_Request.
typedef struct hdwr_pkg__srv__HumanSrv_Request__Sequence
{
  hdwr_pkg__srv__HumanSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hdwr_pkg__srv__HumanSrv_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/HumanSrv in the package hdwr_pkg.
typedef struct hdwr_pkg__srv__HumanSrv_Response
{
  bool success;
} hdwr_pkg__srv__HumanSrv_Response;

// Struct for a sequence of hdwr_pkg__srv__HumanSrv_Response.
typedef struct hdwr_pkg__srv__HumanSrv_Response__Sequence
{
  hdwr_pkg__srv__HumanSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hdwr_pkg__srv__HumanSrv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HDWR_PKG__SRV__DETAIL__HUMAN_SRV__STRUCT_H_
