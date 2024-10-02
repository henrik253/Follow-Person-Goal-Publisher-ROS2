// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from object_tracking_messages:msg/BoundingBox.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "object_tracking_messages/msg/detail/bounding_box__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace object_tracking_messages
{

namespace msg
{

namespace builder
{

class Init_BoundingBox_y_max
{
public:
  explicit Init_BoundingBox_y_max(::object_tracking_messages::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  ::object_tracking_messages::msg::BoundingBox y_max(::object_tracking_messages::msg::BoundingBox::_y_max_type arg)
  {
    msg_.y_max = std::move(arg);
    return std::move(msg_);
  }

private:
  ::object_tracking_messages::msg::BoundingBox msg_;
};

class Init_BoundingBox_x_max
{
public:
  explicit Init_BoundingBox_x_max(::object_tracking_messages::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_y_max x_max(::object_tracking_messages::msg::BoundingBox::_x_max_type arg)
  {
    msg_.x_max = std::move(arg);
    return Init_BoundingBox_y_max(msg_);
  }

private:
  ::object_tracking_messages::msg::BoundingBox msg_;
};

class Init_BoundingBox_y_min
{
public:
  explicit Init_BoundingBox_y_min(::object_tracking_messages::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_x_max y_min(::object_tracking_messages::msg::BoundingBox::_y_min_type arg)
  {
    msg_.y_min = std::move(arg);
    return Init_BoundingBox_x_max(msg_);
  }

private:
  ::object_tracking_messages::msg::BoundingBox msg_;
};

class Init_BoundingBox_x_min
{
public:
  Init_BoundingBox_x_min()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoundingBox_y_min x_min(::object_tracking_messages::msg::BoundingBox::_x_min_type arg)
  {
    msg_.x_min = std::move(arg);
    return Init_BoundingBox_y_min(msg_);
  }

private:
  ::object_tracking_messages::msg::BoundingBox msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::object_tracking_messages::msg::BoundingBox>()
{
  return object_tracking_messages::msg::builder::Init_BoundingBox_x_min();
}

}  // namespace object_tracking_messages

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_
