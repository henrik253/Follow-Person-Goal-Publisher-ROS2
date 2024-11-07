// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from object_tracking_messages:msg/PersonKeyPoint.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__PERSON_KEY_POINT__STRUCT_HPP_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__PERSON_KEY_POINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__object_tracking_messages__msg__PersonKeyPoint __attribute__((deprecated))
#else
# define DEPRECATED__object_tracking_messages__msg__PersonKeyPoint __declspec(deprecated)
#endif

namespace object_tracking_messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PersonKeyPoint_
{
  using Type = PersonKeyPoint_<ContainerAllocator>;

  explicit PersonKeyPoint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->confidence = 0.0f;
    }
  }

  explicit PersonKeyPoint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->confidence = 0.0f;
    }
  }

  // field types and members
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _confidence_type =
    float;
  _confidence_type confidence;

  // setters for named parameter idiom
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    object_tracking_messages::msg::PersonKeyPoint_<ContainerAllocator> *;
  using ConstRawPtr =
    const object_tracking_messages::msg::PersonKeyPoint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<object_tracking_messages::msg::PersonKeyPoint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<object_tracking_messages::msg::PersonKeyPoint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      object_tracking_messages::msg::PersonKeyPoint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<object_tracking_messages::msg::PersonKeyPoint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      object_tracking_messages::msg::PersonKeyPoint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<object_tracking_messages::msg::PersonKeyPoint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<object_tracking_messages::msg::PersonKeyPoint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<object_tracking_messages::msg::PersonKeyPoint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__object_tracking_messages__msg__PersonKeyPoint
    std::shared_ptr<object_tracking_messages::msg::PersonKeyPoint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__object_tracking_messages__msg__PersonKeyPoint
    std::shared_ptr<object_tracking_messages::msg::PersonKeyPoint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PersonKeyPoint_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    return true;
  }
  bool operator!=(const PersonKeyPoint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PersonKeyPoint_

// alias to use template instance with default allocator
using PersonKeyPoint =
  object_tracking_messages::msg::PersonKeyPoint_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace object_tracking_messages

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__PERSON_KEY_POINT__STRUCT_HPP_
