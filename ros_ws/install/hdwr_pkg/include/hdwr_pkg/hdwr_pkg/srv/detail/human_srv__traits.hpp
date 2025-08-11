// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hdwr_pkg:srv/HumanSrv.idl
// generated code does not contain a copyright notice

#ifndef HDWR_PKG__SRV__DETAIL__HUMAN_SRV__TRAITS_HPP_
#define HDWR_PKG__SRV__DETAIL__HUMAN_SRV__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hdwr_pkg/srv/detail/human_srv__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hdwr_pkg
{

namespace srv
{

inline void to_flow_style_yaml(
  const HumanSrv_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: human_action
  {
    out << "human_action: ";
    rosidl_generator_traits::value_to_yaml(msg.human_action, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HumanSrv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: human_action
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "human_action: ";
    rosidl_generator_traits::value_to_yaml(msg.human_action, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HumanSrv_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace hdwr_pkg

namespace rosidl_generator_traits
{

[[deprecated("use hdwr_pkg::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hdwr_pkg::srv::HumanSrv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  hdwr_pkg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hdwr_pkg::srv::to_yaml() instead")]]
inline std::string to_yaml(const hdwr_pkg::srv::HumanSrv_Request & msg)
{
  return hdwr_pkg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hdwr_pkg::srv::HumanSrv_Request>()
{
  return "hdwr_pkg::srv::HumanSrv_Request";
}

template<>
inline const char * name<hdwr_pkg::srv::HumanSrv_Request>()
{
  return "hdwr_pkg/srv/HumanSrv_Request";
}

template<>
struct has_fixed_size<hdwr_pkg::srv::HumanSrv_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hdwr_pkg::srv::HumanSrv_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hdwr_pkg::srv::HumanSrv_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace hdwr_pkg
{

namespace srv
{

inline void to_flow_style_yaml(
  const HumanSrv_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HumanSrv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HumanSrv_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace hdwr_pkg

namespace rosidl_generator_traits
{

[[deprecated("use hdwr_pkg::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hdwr_pkg::srv::HumanSrv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  hdwr_pkg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hdwr_pkg::srv::to_yaml() instead")]]
inline std::string to_yaml(const hdwr_pkg::srv::HumanSrv_Response & msg)
{
  return hdwr_pkg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hdwr_pkg::srv::HumanSrv_Response>()
{
  return "hdwr_pkg::srv::HumanSrv_Response";
}

template<>
inline const char * name<hdwr_pkg::srv::HumanSrv_Response>()
{
  return "hdwr_pkg/srv/HumanSrv_Response";
}

template<>
struct has_fixed_size<hdwr_pkg::srv::HumanSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hdwr_pkg::srv::HumanSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hdwr_pkg::srv::HumanSrv_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hdwr_pkg::srv::HumanSrv>()
{
  return "hdwr_pkg::srv::HumanSrv";
}

template<>
inline const char * name<hdwr_pkg::srv::HumanSrv>()
{
  return "hdwr_pkg/srv/HumanSrv";
}

template<>
struct has_fixed_size<hdwr_pkg::srv::HumanSrv>
  : std::integral_constant<
    bool,
    has_fixed_size<hdwr_pkg::srv::HumanSrv_Request>::value &&
    has_fixed_size<hdwr_pkg::srv::HumanSrv_Response>::value
  >
{
};

template<>
struct has_bounded_size<hdwr_pkg::srv::HumanSrv>
  : std::integral_constant<
    bool,
    has_bounded_size<hdwr_pkg::srv::HumanSrv_Request>::value &&
    has_bounded_size<hdwr_pkg::srv::HumanSrv_Response>::value
  >
{
};

template<>
struct is_service<hdwr_pkg::srv::HumanSrv>
  : std::true_type
{
};

template<>
struct is_service_request<hdwr_pkg::srv::HumanSrv_Request>
  : std::true_type
{
};

template<>
struct is_service_response<hdwr_pkg::srv::HumanSrv_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // HDWR_PKG__SRV__DETAIL__HUMAN_SRV__TRAITS_HPP_
