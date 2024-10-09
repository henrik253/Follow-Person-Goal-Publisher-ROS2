// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from object_tracking_messages:msg/DetectedPersons.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSONS__STRUCT_HPP_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSONS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'persons'
#include "object_tracking_messages/msg/detail/detected_person__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__object_tracking_messages__msg__DetectedPersons __attribute__((deprecated))
#else
# define DEPRECATED__object_tracking_messages__msg__DetectedPersons __declspec(deprecated)
#endif

namespace object_tracking_messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DetectedPersons_
{
  using Type = DetectedPersons_<ContainerAllocator>;

  explicit DetectedPersons_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit DetectedPersons_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _persons_type =
    std::vector<object_tracking_messages::msg::DetectedPerson_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<object_tracking_messages::msg::DetectedPerson_<ContainerAllocator>>>;
  _persons_type persons;

  // setters for named parameter idiom
  Type & set__persons(
    const std::vector<object_tracking_messages::msg::DetectedPerson_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<object_tracking_messages::msg::DetectedPerson_<ContainerAllocator>>> & _arg)
  {
    this->persons = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    object_tracking_messages::msg::DetectedPersons_<ContainerAllocator> *;
  using ConstRawPtr =
    const object_tracking_messages::msg::DetectedPersons_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<object_tracking_messages::msg::DetectedPersons_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<object_tracking_messages::msg::DetectedPersons_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      object_tracking_messages::msg::DetectedPersons_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<object_tracking_messages::msg::DetectedPersons_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      object_tracking_messages::msg::DetectedPersons_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<object_tracking_messages::msg::DetectedPersons_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<object_tracking_messages::msg::DetectedPersons_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<object_tracking_messages::msg::DetectedPersons_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__object_tracking_messages__msg__DetectedPersons
    std::shared_ptr<object_tracking_messages::msg::DetectedPersons_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__object_tracking_messages__msg__DetectedPersons
    std::shared_ptr<object_tracking_messages::msg::DetectedPersons_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectedPersons_ & other) const
  {
    if (this->persons != other.persons) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectedPersons_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectedPersons_

// alias to use template instance with default allocator
using DetectedPersons =
  object_tracking_messages::msg::DetectedPersons_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace object_tracking_messages

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSONS__STRUCT_HPP_
