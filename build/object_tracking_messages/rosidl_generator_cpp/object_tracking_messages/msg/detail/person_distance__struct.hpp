// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from object_tracking_messages:msg/PersonDistance.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__PERSON_DISTANCE__STRUCT_HPP_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__PERSON_DISTANCE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'detected_persons'
#include "object_tracking_messages/msg/detail/detected_persons__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__object_tracking_messages__msg__PersonDistance __attribute__((deprecated))
#else
# define DEPRECATED__object_tracking_messages__msg__PersonDistance __declspec(deprecated)
#endif

namespace object_tracking_messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PersonDistance_
{
  using Type = PersonDistance_<ContainerAllocator>;

  explicit PersonDistance_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : detected_persons(_init)
  {
    (void)_init;
  }

  explicit PersonDistance_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : detected_persons(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _detected_persons_type =
    object_tracking_messages::msg::DetectedPersons_<ContainerAllocator>;
  _detected_persons_type detected_persons;
  using _distances_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _distances_type distances;
  using _real_world_coordinates_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _real_world_coordinates_type real_world_coordinates;
  using _nose_real_world_coordinates_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _nose_real_world_coordinates_type nose_real_world_coordinates;
  using _left_eye_real_world_coordinates_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _left_eye_real_world_coordinates_type left_eye_real_world_coordinates;
  using _right_eye_real_world_coordinates_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _right_eye_real_world_coordinates_type right_eye_real_world_coordinates;
  using _left_ear_real_world_coordinates_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _left_ear_real_world_coordinates_type left_ear_real_world_coordinates;
  using _right_ear_real_world_coordinates_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _right_ear_real_world_coordinates_type right_ear_real_world_coordinates;
  using _left_shoulder_real_world_coordinates_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _left_shoulder_real_world_coordinates_type left_shoulder_real_world_coordinates;
  using _right_shoulder_real_world_coordinates_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _right_shoulder_real_world_coordinates_type right_shoulder_real_world_coordinates;
  using _left_elbow_real_world_coordinates_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _left_elbow_real_world_coordinates_type left_elbow_real_world_coordinates;
  using _right_elbow_real_world_coordinates_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _right_elbow_real_world_coordinates_type right_elbow_real_world_coordinates;
  using _left_wrist_real_world_coordinates_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _left_wrist_real_world_coordinates_type left_wrist_real_world_coordinates;
  using _right_wrist_real_world_coordinates_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _right_wrist_real_world_coordinates_type right_wrist_real_world_coordinates;
  using _left_hip_real_world_coordinates_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _left_hip_real_world_coordinates_type left_hip_real_world_coordinates;
  using _right_hip_real_world_coordinates_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _right_hip_real_world_coordinates_type right_hip_real_world_coordinates;
  using _left_knee_real_world_coordinates_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _left_knee_real_world_coordinates_type left_knee_real_world_coordinates;
  using _right_knee_real_world_coordinates_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _right_knee_real_world_coordinates_type right_knee_real_world_coordinates;
  using _left_ankle_real_world_coordinates_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _left_ankle_real_world_coordinates_type left_ankle_real_world_coordinates;
  using _right_ankle_real_world_coordinates_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _right_ankle_real_world_coordinates_type right_ankle_real_world_coordinates;

  // setters for named parameter idiom
  Type & set__detected_persons(
    const object_tracking_messages::msg::DetectedPersons_<ContainerAllocator> & _arg)
  {
    this->detected_persons = _arg;
    return *this;
  }
  Type & set__distances(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->distances = _arg;
    return *this;
  }
  Type & set__real_world_coordinates(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->real_world_coordinates = _arg;
    return *this;
  }
  Type & set__nose_real_world_coordinates(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->nose_real_world_coordinates = _arg;
    return *this;
  }
  Type & set__left_eye_real_world_coordinates(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->left_eye_real_world_coordinates = _arg;
    return *this;
  }
  Type & set__right_eye_real_world_coordinates(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->right_eye_real_world_coordinates = _arg;
    return *this;
  }
  Type & set__left_ear_real_world_coordinates(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->left_ear_real_world_coordinates = _arg;
    return *this;
  }
  Type & set__right_ear_real_world_coordinates(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->right_ear_real_world_coordinates = _arg;
    return *this;
  }
  Type & set__left_shoulder_real_world_coordinates(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->left_shoulder_real_world_coordinates = _arg;
    return *this;
  }
  Type & set__right_shoulder_real_world_coordinates(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->right_shoulder_real_world_coordinates = _arg;
    return *this;
  }
  Type & set__left_elbow_real_world_coordinates(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->left_elbow_real_world_coordinates = _arg;
    return *this;
  }
  Type & set__right_elbow_real_world_coordinates(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->right_elbow_real_world_coordinates = _arg;
    return *this;
  }
  Type & set__left_wrist_real_world_coordinates(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->left_wrist_real_world_coordinates = _arg;
    return *this;
  }
  Type & set__right_wrist_real_world_coordinates(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->right_wrist_real_world_coordinates = _arg;
    return *this;
  }
  Type & set__left_hip_real_world_coordinates(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->left_hip_real_world_coordinates = _arg;
    return *this;
  }
  Type & set__right_hip_real_world_coordinates(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->right_hip_real_world_coordinates = _arg;
    return *this;
  }
  Type & set__left_knee_real_world_coordinates(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->left_knee_real_world_coordinates = _arg;
    return *this;
  }
  Type & set__right_knee_real_world_coordinates(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->right_knee_real_world_coordinates = _arg;
    return *this;
  }
  Type & set__left_ankle_real_world_coordinates(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->left_ankle_real_world_coordinates = _arg;
    return *this;
  }
  Type & set__right_ankle_real_world_coordinates(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->right_ankle_real_world_coordinates = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    object_tracking_messages::msg::PersonDistance_<ContainerAllocator> *;
  using ConstRawPtr =
    const object_tracking_messages::msg::PersonDistance_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<object_tracking_messages::msg::PersonDistance_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<object_tracking_messages::msg::PersonDistance_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      object_tracking_messages::msg::PersonDistance_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<object_tracking_messages::msg::PersonDistance_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      object_tracking_messages::msg::PersonDistance_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<object_tracking_messages::msg::PersonDistance_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<object_tracking_messages::msg::PersonDistance_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<object_tracking_messages::msg::PersonDistance_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__object_tracking_messages__msg__PersonDistance
    std::shared_ptr<object_tracking_messages::msg::PersonDistance_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__object_tracking_messages__msg__PersonDistance
    std::shared_ptr<object_tracking_messages::msg::PersonDistance_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PersonDistance_ & other) const
  {
    if (this->detected_persons != other.detected_persons) {
      return false;
    }
    if (this->distances != other.distances) {
      return false;
    }
    if (this->real_world_coordinates != other.real_world_coordinates) {
      return false;
    }
    if (this->nose_real_world_coordinates != other.nose_real_world_coordinates) {
      return false;
    }
    if (this->left_eye_real_world_coordinates != other.left_eye_real_world_coordinates) {
      return false;
    }
    if (this->right_eye_real_world_coordinates != other.right_eye_real_world_coordinates) {
      return false;
    }
    if (this->left_ear_real_world_coordinates != other.left_ear_real_world_coordinates) {
      return false;
    }
    if (this->right_ear_real_world_coordinates != other.right_ear_real_world_coordinates) {
      return false;
    }
    if (this->left_shoulder_real_world_coordinates != other.left_shoulder_real_world_coordinates) {
      return false;
    }
    if (this->right_shoulder_real_world_coordinates != other.right_shoulder_real_world_coordinates) {
      return false;
    }
    if (this->left_elbow_real_world_coordinates != other.left_elbow_real_world_coordinates) {
      return false;
    }
    if (this->right_elbow_real_world_coordinates != other.right_elbow_real_world_coordinates) {
      return false;
    }
    if (this->left_wrist_real_world_coordinates != other.left_wrist_real_world_coordinates) {
      return false;
    }
    if (this->right_wrist_real_world_coordinates != other.right_wrist_real_world_coordinates) {
      return false;
    }
    if (this->left_hip_real_world_coordinates != other.left_hip_real_world_coordinates) {
      return false;
    }
    if (this->right_hip_real_world_coordinates != other.right_hip_real_world_coordinates) {
      return false;
    }
    if (this->left_knee_real_world_coordinates != other.left_knee_real_world_coordinates) {
      return false;
    }
    if (this->right_knee_real_world_coordinates != other.right_knee_real_world_coordinates) {
      return false;
    }
    if (this->left_ankle_real_world_coordinates != other.left_ankle_real_world_coordinates) {
      return false;
    }
    if (this->right_ankle_real_world_coordinates != other.right_ankle_real_world_coordinates) {
      return false;
    }
    return true;
  }
  bool operator!=(const PersonDistance_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PersonDistance_

// alias to use template instance with default allocator
using PersonDistance =
  object_tracking_messages::msg::PersonDistance_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace object_tracking_messages

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__PERSON_DISTANCE__STRUCT_HPP_
