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

class Init_PersonDistance_distances
{
public:
  explicit Init_PersonDistance_distances(::object_tracking_messages::msg::PersonDistance & msg)
  : msg_(msg)
  {}
  ::object_tracking_messages::msg::PersonDistance distances(::object_tracking_messages::msg::PersonDistance::_distances_type arg)
  {
    msg_.distances = std::move(arg);
    return std::move(msg_);
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
