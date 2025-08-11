// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hdwr_pkg:srv/HumanSrv.idl
// generated code does not contain a copyright notice

#ifndef HDWR_PKG__SRV__DETAIL__HUMAN_SRV__STRUCT_HPP_
#define HDWR_PKG__SRV__DETAIL__HUMAN_SRV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hdwr_pkg__srv__HumanSrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__hdwr_pkg__srv__HumanSrv_Request __declspec(deprecated)
#endif

namespace hdwr_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct HumanSrv_Request_
{
  using Type = HumanSrv_Request_<ContainerAllocator>;

  explicit HumanSrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->human_action = "";
    }
  }

  explicit HumanSrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : human_action(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->human_action = "";
    }
  }

  // field types and members
  using _human_action_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _human_action_type human_action;

  // setters for named parameter idiom
  Type & set__human_action(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->human_action = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hdwr_pkg::srv::HumanSrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const hdwr_pkg::srv::HumanSrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hdwr_pkg::srv::HumanSrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hdwr_pkg::srv::HumanSrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hdwr_pkg::srv::HumanSrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hdwr_pkg::srv::HumanSrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hdwr_pkg::srv::HumanSrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hdwr_pkg::srv::HumanSrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hdwr_pkg::srv::HumanSrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hdwr_pkg::srv::HumanSrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hdwr_pkg__srv__HumanSrv_Request
    std::shared_ptr<hdwr_pkg::srv::HumanSrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hdwr_pkg__srv__HumanSrv_Request
    std::shared_ptr<hdwr_pkg::srv::HumanSrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HumanSrv_Request_ & other) const
  {
    if (this->human_action != other.human_action) {
      return false;
    }
    return true;
  }
  bool operator!=(const HumanSrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HumanSrv_Request_

// alias to use template instance with default allocator
using HumanSrv_Request =
  hdwr_pkg::srv::HumanSrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hdwr_pkg


#ifndef _WIN32
# define DEPRECATED__hdwr_pkg__srv__HumanSrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__hdwr_pkg__srv__HumanSrv_Response __declspec(deprecated)
#endif

namespace hdwr_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct HumanSrv_Response_
{
  using Type = HumanSrv_Response_<ContainerAllocator>;

  explicit HumanSrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit HumanSrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hdwr_pkg::srv::HumanSrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const hdwr_pkg::srv::HumanSrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hdwr_pkg::srv::HumanSrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hdwr_pkg::srv::HumanSrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hdwr_pkg::srv::HumanSrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hdwr_pkg::srv::HumanSrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hdwr_pkg::srv::HumanSrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hdwr_pkg::srv::HumanSrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hdwr_pkg::srv::HumanSrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hdwr_pkg::srv::HumanSrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hdwr_pkg__srv__HumanSrv_Response
    std::shared_ptr<hdwr_pkg::srv::HumanSrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hdwr_pkg__srv__HumanSrv_Response
    std::shared_ptr<hdwr_pkg::srv::HumanSrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HumanSrv_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const HumanSrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HumanSrv_Response_

// alias to use template instance with default allocator
using HumanSrv_Response =
  hdwr_pkg::srv::HumanSrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hdwr_pkg

namespace hdwr_pkg
{

namespace srv
{

struct HumanSrv
{
  using Request = hdwr_pkg::srv::HumanSrv_Request;
  using Response = hdwr_pkg::srv::HumanSrv_Response;
};

}  // namespace srv

}  // namespace hdwr_pkg

#endif  // HDWR_PKG__SRV__DETAIL__HUMAN_SRV__STRUCT_HPP_
