// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from object_tracking_messages:msg/DetectedPersons.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSONS__BUILDER_HPP_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSONS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "object_tracking_messages/msg/detail/detected_persons__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace object_tracking_messages
{

namespace msg
{

namespace builder
{

class Init_DetectedPersons_persons
{
public:
  Init_DetectedPersons_persons()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::object_tracking_messages::msg::DetectedPersons persons(::object_tracking_messages::msg::DetectedPersons::_persons_type arg)
  {
    msg_.persons = std::move(arg);
    return std::move(msg_);
  }

private:
  ::object_tracking_messages::msg::DetectedPersons msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::object_tracking_messages::msg::DetectedPersons>()
{
  return object_tracking_messages::msg::builder::Init_DetectedPersons_persons();
}

}  // namespace object_tracking_messages

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSONS__BUILDER_HPP_
