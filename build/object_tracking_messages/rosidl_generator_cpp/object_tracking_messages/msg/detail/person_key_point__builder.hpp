// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from object_tracking_messages:msg/PersonKeyPoint.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__PERSON_KEY_POINT__BUILDER_HPP_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__PERSON_KEY_POINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "object_tracking_messages/msg/detail/person_key_point__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace object_tracking_messages
{

namespace msg
{

namespace builder
{

class Init_PersonKeyPoint_confidence
{
public:
  explicit Init_PersonKeyPoint_confidence(::object_tracking_messages::msg::PersonKeyPoint & msg)
  : msg_(msg)
  {}
  ::object_tracking_messages::msg::PersonKeyPoint confidence(::object_tracking_messages::msg::PersonKeyPoint::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::object_tracking_messages::msg::PersonKeyPoint msg_;
};

class Init_PersonKeyPoint_y
{
public:
  explicit Init_PersonKeyPoint_y(::object_tracking_messages::msg::PersonKeyPoint & msg)
  : msg_(msg)
  {}
  Init_PersonKeyPoint_confidence y(::object_tracking_messages::msg::PersonKeyPoint::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_PersonKeyPoint_confidence(msg_);
  }

private:
  ::object_tracking_messages::msg::PersonKeyPoint msg_;
};

class Init_PersonKeyPoint_x
{
public:
  Init_PersonKeyPoint_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PersonKeyPoint_y x(::object_tracking_messages::msg::PersonKeyPoint::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_PersonKeyPoint_y(msg_);
  }

private:
  ::object_tracking_messages::msg::PersonKeyPoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::object_tracking_messages::msg::PersonKeyPoint>()
{
  return object_tracking_messages::msg::builder::Init_PersonKeyPoint_x();
}

}  // namespace object_tracking_messages

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__PERSON_KEY_POINT__BUILDER_HPP_
