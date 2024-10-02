// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from object_tracking_messages:msg/DetectedPerson.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSON__BUILDER_HPP_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSON__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "object_tracking_messages/msg/detail/detected_person__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace object_tracking_messages
{

namespace msg
{

namespace builder
{

class Init_DetectedPerson_bbox
{
public:
  explicit Init_DetectedPerson_bbox(::object_tracking_messages::msg::DetectedPerson & msg)
  : msg_(msg)
  {}
  ::object_tracking_messages::msg::DetectedPerson bbox(::object_tracking_messages::msg::DetectedPerson::_bbox_type arg)
  {
    msg_.bbox = std::move(arg);
    return std::move(msg_);
  }

private:
  ::object_tracking_messages::msg::DetectedPerson msg_;
};

class Init_DetectedPerson_id
{
public:
  Init_DetectedPerson_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectedPerson_bbox id(::object_tracking_messages::msg::DetectedPerson::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_DetectedPerson_bbox(msg_);
  }

private:
  ::object_tracking_messages::msg::DetectedPerson msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::object_tracking_messages::msg::DetectedPerson>()
{
  return object_tracking_messages::msg::builder::Init_DetectedPerson_id();
}

}  // namespace object_tracking_messages

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSON__BUILDER_HPP_
