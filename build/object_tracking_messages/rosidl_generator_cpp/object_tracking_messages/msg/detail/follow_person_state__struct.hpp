// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from object_tracking_messages:msg/FollowPersonState.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__FOLLOW_PERSON_STATE__STRUCT_HPP_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__FOLLOW_PERSON_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__object_tracking_messages__msg__FollowPersonState __attribute__((deprecated))
#else
# define DEPRECATED__object_tracking_messages__msg__FollowPersonState __declspec(deprecated)
#endif

namespace object_tracking_messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FollowPersonState_
{
  using Type = FollowPersonState_<ContainerAllocator>;

  explicit FollowPersonState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = "";
      this->id = 0l;
    }
  }

  explicit FollowPersonState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : state(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = "";
      this->id = 0l;
    }
  }

  // field types and members
  using _state_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _state_type state;
  using _id_type =
    int32_t;
  _id_type id;

  // setters for named parameter idiom
  Type & set__state(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    object_tracking_messages::msg::FollowPersonState_<ContainerAllocator> *;
  using ConstRawPtr =
    const object_tracking_messages::msg::FollowPersonState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<object_tracking_messages::msg::FollowPersonState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<object_tracking_messages::msg::FollowPersonState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      object_tracking_messages::msg::FollowPersonState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<object_tracking_messages::msg::FollowPersonState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      object_tracking_messages::msg::FollowPersonState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<object_tracking_messages::msg::FollowPersonState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<object_tracking_messages::msg::FollowPersonState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<object_tracking_messages::msg::FollowPersonState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__object_tracking_messages__msg__FollowPersonState
    std::shared_ptr<object_tracking_messages::msg::FollowPersonState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__object_tracking_messages__msg__FollowPersonState
    std::shared_ptr<object_tracking_messages::msg::FollowPersonState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FollowPersonState_ & other) const
  {
    if (this->state != other.state) {
      return false;
    }
    if (this->id != other.id) {
      return false;
    }
    return true;
  }
  bool operator!=(const FollowPersonState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FollowPersonState_

// alias to use template instance with default allocator
using FollowPersonState =
  object_tracking_messages::msg::FollowPersonState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace object_tracking_messages

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__FOLLOW_PERSON_STATE__STRUCT_HPP_
