// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from object_tracking_messages:msg/PersonDistance.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__PERSON_DISTANCE__BUILDER_HPP_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__PERSON_DISTANCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "object_tracking_messages/msg/detail/person_distance__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace object_tracking_messages
{

namespace msg
{

namespace builder
{

class Init_PersonDistance_right_ankle_real_world_coordinates
{
public:
  explicit Init_PersonDistance_right_ankle_real_world_coordinates(::object_tracking_messages::msg::PersonDistance & msg)
  : msg_(msg)
  {}
  ::object_tracking_messages::msg::PersonDistance right_ankle_real_world_coordinates(::object_tracking_messages::msg::PersonDistance::_right_ankle_real_world_coordinates_type arg)
  {
    msg_.right_ankle_real_world_coordinates = std::move(arg);
    return std::move(msg_);
  }

private:
  ::object_tracking_messages::msg::PersonDistance msg_;
};

class Init_PersonDistance_left_ankle_real_world_coordinates
{
public:
  explicit Init_PersonDistance_left_ankle_real_world_coordinates(::object_tracking_messages::msg::PersonDistance & msg)
  : msg_(msg)
  {}
  Init_PersonDistance_right_ankle_real_world_coordinates left_ankle_real_world_coordinates(::object_tracking_messages::msg::PersonDistance::_left_ankle_real_world_coordinates_type arg)
  {
    msg_.left_ankle_real_world_coordinates = std::move(arg);
    return Init_PersonDistance_right_ankle_real_world_coordinates(msg_);
  }

private:
  ::object_tracking_messages::msg::PersonDistance msg_;
};

class Init_PersonDistance_right_knee_real_world_coordinates
{
public:
  explicit Init_PersonDistance_right_knee_real_world_coordinates(::object_tracking_messages::msg::PersonDistance & msg)
  : msg_(msg)
  {}
  Init_PersonDistance_left_ankle_real_world_coordinates right_knee_real_world_coordinates(::object_tracking_messages::msg::PersonDistance::_right_knee_real_world_coordinates_type arg)
  {
    msg_.right_knee_real_world_coordinates = std::move(arg);
    return Init_PersonDistance_left_ankle_real_world_coordinates(msg_);
  }

private:
  ::object_tracking_messages::msg::PersonDistance msg_;
};

class Init_PersonDistance_left_knee_real_world_coordinates
{
public:
  explicit Init_PersonDistance_left_knee_real_world_coordinates(::object_tracking_messages::msg::PersonDistance & msg)
  : msg_(msg)
  {}
  Init_PersonDistance_right_knee_real_world_coordinates left_knee_real_world_coordinates(::object_tracking_messages::msg::PersonDistance::_left_knee_real_world_coordinates_type arg)
  {
    msg_.left_knee_real_world_coordinates = std::move(arg);
    return Init_PersonDistance_right_knee_real_world_coordinates(msg_);
  }

private:
  ::object_tracking_messages::msg::PersonDistance msg_;
};

class Init_PersonDistance_right_hip_real_world_coordinates
{
public:
  explicit Init_PersonDistance_right_hip_real_world_coordinates(::object_tracking_messages::msg::PersonDistance & msg)
  : msg_(msg)
  {}
  Init_PersonDistance_left_knee_real_world_coordinates right_hip_real_world_coordinates(::object_tracking_messages::msg::PersonDistance::_right_hip_real_world_coordinates_type arg)
  {
    msg_.right_hip_real_world_coordinates = std::move(arg);
    return Init_PersonDistance_left_knee_real_world_coordinates(msg_);
  }

private:
  ::object_tracking_messages::msg::PersonDistance msg_;
};

class Init_PersonDistance_left_hip_real_world_coordinates
{
public:
  explicit Init_PersonDistance_left_hip_real_world_coordinates(::object_tracking_messages::msg::PersonDistance & msg)
  : msg_(msg)
  {}
  Init_PersonDistance_right_hip_real_world_coordinates left_hip_real_world_coordinates(::object_tracking_messages::msg::PersonDistance::_left_hip_real_world_coordinates_type arg)
  {
    msg_.left_hip_real_world_coordinates = std::move(arg);
    return Init_PersonDistance_right_hip_real_world_coordinates(msg_);
  }

private:
  ::object_tracking_messages::msg::PersonDistance msg_;
};

class Init_PersonDistance_right_wrist_real_world_coordinates
{
public:
  explicit Init_PersonDistance_right_wrist_real_world_coordinates(::object_tracking_messages::msg::PersonDistance & msg)
  : msg_(msg)
  {}
  Init_PersonDistance_left_hip_real_world_coordinates right_wrist_real_world_coordinates(::object_tracking_messages::msg::PersonDistance::_right_wrist_real_world_coordinates_type arg)
  {
    msg_.right_wrist_real_world_coordinates = std::move(arg);
    return Init_PersonDistance_left_hip_real_world_coordinates(msg_);
  }

private:
  ::object_tracking_messages::msg::PersonDistance msg_;
};

class Init_PersonDistance_left_wrist_real_world_coordinates
{
public:
  explicit Init_PersonDistance_left_wrist_real_world_coordinates(::object_tracking_messages::msg::PersonDistance & msg)
  : msg_(msg)
  {}
  Init_PersonDistance_right_wrist_real_world_coordinates left_wrist_real_world_coordinates(::object_tracking_messages::msg::PersonDistance::_left_wrist_real_world_coordinates_type arg)
  {
    msg_.left_wrist_real_world_coordinates = std::move(arg);
    return Init_PersonDistance_right_wrist_real_world_coordinates(msg_);
  }

private:
  ::object_tracking_messages::msg::PersonDistance msg_;
};

class Init_PersonDistance_right_elbow_real_world_coordinates
{
public:
  explicit Init_PersonDistance_right_elbow_real_world_coordinates(::object_tracking_messages::msg::PersonDistance & msg)
  : msg_(msg)
  {}
  Init_PersonDistance_left_wrist_real_world_coordinates right_elbow_real_world_coordinates(::object_tracking_messages::msg::PersonDistance::_right_elbow_real_world_coordinates_type arg)
  {
    msg_.right_elbow_real_world_coordinates = std::move(arg);
    return Init_PersonDistance_left_wrist_real_world_coordinates(msg_);
  }

private:
  ::object_tracking_messages::msg::PersonDistance msg_;
};

class Init_PersonDistance_left_elbow_real_world_coordinates
{
public:
  explicit Init_PersonDistance_left_elbow_real_world_coordinates(::object_tracking_messages::msg::PersonDistance & msg)
  : msg_(msg)
  {}
  Init_PersonDistance_right_elbow_real_world_coordinates left_elbow_real_world_coordinates(::object_tracking_messages::msg::PersonDistance::_left_elbow_real_world_coordinates_type arg)
  {
    msg_.left_elbow_real_world_coordinates = std::move(arg);
    return Init_PersonDistance_right_elbow_real_world_coordinates(msg_);
  }

private:
  ::object_tracking_messages::msg::PersonDistance msg_;
};

class Init_PersonDistance_right_shoulder_real_world_coordinates
{
public:
  explicit Init_PersonDistance_right_shoulder_real_world_coordinates(::object_tracking_messages::msg::PersonDistance & msg)
  : msg_(msg)
  {}
  Init_PersonDistance_left_elbow_real_world_coordinates right_shoulder_real_world_coordinates(::object_tracking_messages::msg::PersonDistance::_right_shoulder_real_world_coordinates_type arg)
  {
    msg_.right_shoulder_real_world_coordinates = std::move(arg);
    return Init_PersonDistance_left_elbow_real_world_coordinates(msg_);
  }

private:
  ::object_tracking_messages::msg::PersonDistance msg_;
};

class Init_PersonDistance_left_shoulder_real_world_coordinates
{
public:
  explicit Init_PersonDistance_left_shoulder_real_world_coordinates(::object_tracking_messages::msg::PersonDistance & msg)
  : msg_(msg)
  {}
  Init_PersonDistance_right_shoulder_real_world_coordinates left_shoulder_real_world_coordinates(::object_tracking_messages::msg::PersonDistance::_left_shoulder_real_world_coordinates_type arg)
  {
    msg_.left_shoulder_real_world_coordinates = std::move(arg);
    return Init_PersonDistance_right_shoulder_real_world_coordinates(msg_);
  }

private:
  ::object_tracking_messages::msg::PersonDistance msg_;
};

class Init_PersonDistance_right_ear_real_world_coordinates
{
public:
  explicit Init_PersonDistance_right_ear_real_world_coordinates(::object_tracking_messages::msg::PersonDistance & msg)
  : msg_(msg)
  {}
  Init_PersonDistance_left_shoulder_real_world_coordinates right_ear_real_world_coordinates(::object_tracking_messages::msg::PersonDistance::_right_ear_real_world_coordinates_type arg)
  {
    msg_.right_ear_real_world_coordinates = std::move(arg);
    return Init_PersonDistance_left_shoulder_real_world_coordinates(msg_);
  }

private:
  ::object_tracking_messages::msg::PersonDistance msg_;
};

class Init_PersonDistance_left_ear_real_world_coordinates
{
public:
  explicit Init_PersonDistance_left_ear_real_world_coordinates(::object_tracking_messages::msg::PersonDistance & msg)
  : msg_(msg)
  {}
  Init_PersonDistance_right_ear_real_world_coordinates left_ear_real_world_coordinates(::object_tracking_messages::msg::PersonDistance::_left_ear_real_world_coordinates_type arg)
  {
    msg_.left_ear_real_world_coordinates = std::move(arg);
    return Init_PersonDistance_right_ear_real_world_coordinates(msg_);
  }

private:
  ::object_tracking_messages::msg::PersonDistance msg_;
};

class Init_PersonDistance_right_eye_real_world_coordinates
{
public:
  explicit Init_PersonDistance_right_eye_real_world_coordinates(::object_tracking_messages::msg::PersonDistance & msg)
  : msg_(msg)
  {}
  Init_PersonDistance_left_ear_real_world_coordinates right_eye_real_world_coordinates(::object_tracking_messages::msg::PersonDistance::_right_eye_real_world_coordinates_type arg)
  {
    msg_.right_eye_real_world_coordinates = std::move(arg);
    return Init_PersonDistance_left_ear_real_world_coordinates(msg_);
  }

private:
  ::object_tracking_messages::msg::PersonDistance msg_;
};

class Init_PersonDistance_left_eye_real_world_coordinates
{
public:
  explicit Init_PersonDistance_left_eye_real_world_coordinates(::object_tracking_messages::msg::PersonDistance & msg)
  : msg_(msg)
  {}
  Init_PersonDistance_right_eye_real_world_coordinates left_eye_real_world_coordinates(::object_tracking_messages::msg::PersonDistance::_left_eye_real_world_coordinates_type arg)
  {
    msg_.left_eye_real_world_coordinates = std::move(arg);
    return Init_PersonDistance_right_eye_real_world_coordinates(msg_);
  }

private:
  ::object_tracking_messages::msg::PersonDistance msg_;
};

class Init_PersonDistance_nose_real_world_coordinates
{
public:
  explicit Init_PersonDistance_nose_real_world_coordinates(::object_tracking_messages::msg::PersonDistance & msg)
  : msg_(msg)
  {}
  Init_PersonDistance_left_eye_real_world_coordinates nose_real_world_coordinates(::object_tracking_messages::msg::PersonDistance::_nose_real_world_coordinates_type arg)
  {
    msg_.nose_real_world_coordinates = std::move(arg);
    return Init_PersonDistance_left_eye_real_world_coordinates(msg_);
  }

private:
  ::object_tracking_messages::msg::PersonDistance msg_;
};

class Init_PersonDistance_real_world_coordinates
{
public:
  explicit Init_PersonDistance_real_world_coordinates(::object_tracking_messages::msg::PersonDistance & msg)
  : msg_(msg)
  {}
  Init_PersonDistance_nose_real_world_coordinates real_world_coordinates(::object_tracking_messages::msg::PersonDistance::_real_world_coordinates_type arg)
  {
    msg_.real_world_coordinates = std::move(arg);
    return Init_PersonDistance_nose_real_world_coordinates(msg_);
  }

private:
  ::object_tracking_messages::msg::PersonDistance msg_;
};

class Init_PersonDistance_distances
{
public:
  explicit Init_PersonDistance_distances(::object_tracking_messages::msg::PersonDistance & msg)
  : msg_(msg)
  {}
  Init_PersonDistance_real_world_coordinates distances(::object_tracking_messages::msg::PersonDistance::_distances_type arg)
  {
    msg_.distances = std::move(arg);
    return Init_PersonDistance_real_world_coordinates(msg_);
  }

private:
  ::object_tracking_messages::msg::PersonDistance msg_;
};

class Init_PersonDistance_detected_persons
{
public:
  Init_PersonDistance_detected_persons()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PersonDistance_distances detected_persons(::object_tracking_messages::msg::PersonDistance::_detected_persons_type arg)
  {
    msg_.detected_persons = std::move(arg);
    return Init_PersonDistance_distances(msg_);
  }

private:
  ::object_tracking_messages::msg::PersonDistance msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::object_tracking_messages::msg::PersonDistance>()
{
  return object_tracking_messages::msg::builder::Init_PersonDistance_detected_persons();
}

}  // namespace object_tracking_messages

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__PERSON_DISTANCE__BUILDER_HPP_
