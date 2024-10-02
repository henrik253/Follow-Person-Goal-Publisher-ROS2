// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from object_tracking_messages:msg/DetectedPerson.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSON__STRUCT_HPP_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSON__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'bbox'
#include "object_tracking_messages/msg/detail/bounding_box__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__object_tracking_messages__msg__DetectedPerson __attribute__((deprecated))
#else
# define DEPRECATED__object_tracking_messages__msg__DetectedPerson __declspec(deprecated)
#endif

namespace object_tracking_messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DetectedPerson_
{
  using Type = DetectedPerson_<ContainerAllocator>;

  explicit DetectedPerson_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : bbox(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
    }
  }

  explicit DetectedPerson_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : bbox(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _bbox_type =
    object_tracking_messages::msg::BoundingBox_<ContainerAllocator>;
  _bbox_type bbox;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__bbox(
    const object_tracking_messages::msg::BoundingBox_<ContainerAllocator> & _arg)
  {
    this->bbox = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    object_tracking_messages::msg::DetectedPerson_<ContainerAllocator> *;
  using ConstRawPtr =
    const object_tracking_messages::msg::DetectedPerson_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<object_tracking_messages::msg::DetectedPerson_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<object_tracking_messages::msg::DetectedPerson_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      object_tracking_messages::msg::DetectedPerson_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<object_tracking_messages::msg::DetectedPerson_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      object_tracking_messages::msg::DetectedPerson_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<object_tracking_messages::msg::DetectedPerson_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<object_tracking_messages::msg::DetectedPerson_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<object_tracking_messages::msg::DetectedPerson_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__object_tracking_messages__msg__DetectedPerson
    std::shared_ptr<object_tracking_messages::msg::DetectedPerson_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__object_tracking_messages__msg__DetectedPerson
    std::shared_ptr<object_tracking_messages::msg::DetectedPerson_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectedPerson_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->bbox != other.bbox) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectedPerson_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectedPerson_

// alias to use template instance with default allocator
using DetectedPerson =
  object_tracking_messages::msg::DetectedPerson_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace object_tracking_messages

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSON__STRUCT_HPP_
