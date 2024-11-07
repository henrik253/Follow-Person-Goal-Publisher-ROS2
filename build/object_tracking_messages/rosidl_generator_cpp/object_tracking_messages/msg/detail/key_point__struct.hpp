// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from object_tracking_messages:msg/KeyPoint.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__KEY_POINT__STRUCT_HPP_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__KEY_POINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__object_tracking_messages__msg__KeyPoint __attribute__((deprecated))
#else
# define DEPRECATED__object_tracking_messages__msg__KeyPoint __declspec(deprecated)
#endif

namespace object_tracking_messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct KeyPoint_
{
  using Type = KeyPoint_<ContainerAllocator>;

  explicit KeyPoint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit KeyPoint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    object_tracking_messages::msg::KeyPoint_<ContainerAllocator> *;
  using ConstRawPtr =
    const object_tracking_messages::msg::KeyPoint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<object_tracking_messages::msg::KeyPoint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<object_tracking_messages::msg::KeyPoint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      object_tracking_messages::msg::KeyPoint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<object_tracking_messages::msg::KeyPoint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      object_tracking_messages::msg::KeyPoint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<object_tracking_messages::msg::KeyPoint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<object_tracking_messages::msg::KeyPoint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<object_tracking_messages::msg::KeyPoint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__object_tracking_messages__msg__KeyPoint
    std::shared_ptr<object_tracking_messages::msg::KeyPoint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__object_tracking_messages__msg__KeyPoint
    std::shared_ptr<object_tracking_messages::msg::KeyPoint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const KeyPoint_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const KeyPoint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct KeyPoint_

// alias to use template instance with default allocator
using KeyPoint =
  object_tracking_messages::msg::KeyPoint_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace object_tracking_messages

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__KEY_POINT__STRUCT_HPP_
