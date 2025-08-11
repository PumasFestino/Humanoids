// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hdwr_pkg:srv/HumanSrv.idl
// generated code does not contain a copyright notice

#ifndef HDWR_PKG__SRV__DETAIL__HUMAN_SRV__BUILDER_HPP_
#define HDWR_PKG__SRV__DETAIL__HUMAN_SRV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hdwr_pkg/srv/detail/human_srv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hdwr_pkg
{

namespace srv
{

namespace builder
{

class Init_HumanSrv_Request_human_action
{
public:
  Init_HumanSrv_Request_human_action()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hdwr_pkg::srv::HumanSrv_Request human_action(::hdwr_pkg::srv::HumanSrv_Request::_human_action_type arg)
  {
    msg_.human_action = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hdwr_pkg::srv::HumanSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hdwr_pkg::srv::HumanSrv_Request>()
{
  return hdwr_pkg::srv::builder::Init_HumanSrv_Request_human_action();
}

}  // namespace hdwr_pkg


namespace hdwr_pkg
{

namespace srv
{

namespace builder
{

class Init_HumanSrv_Response_success
{
public:
  Init_HumanSrv_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hdwr_pkg::srv::HumanSrv_Response success(::hdwr_pkg::srv::HumanSrv_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hdwr_pkg::srv::HumanSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hdwr_pkg::srv::HumanSrv_Response>()
{
  return hdwr_pkg::srv::builder::Init_HumanSrv_Response_success();
}

}  // namespace hdwr_pkg

#endif  // HDWR_PKG__SRV__DETAIL__HUMAN_SRV__BUILDER_HPP_
