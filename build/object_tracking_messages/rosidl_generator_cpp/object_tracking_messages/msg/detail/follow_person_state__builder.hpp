// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from object_tracking_messages:msg/FollowPersonState.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__FOLLOW_PERSON_STATE__BUILDER_HPP_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__FOLLOW_PERSON_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "object_tracking_messages/msg/detail/follow_person_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace object_tracking_messages
{

namespace msg
{

namespace builder
{

class Init_FollowPersonState_id
{
public:
  explicit Init_FollowPersonState_id(::object_tracking_messages::msg::FollowPersonState & msg)
  : msg_(msg)
  {}
  ::object_tracking_messages::msg::FollowPersonState id(::object_tracking_messages::msg::FollowPersonState::_id_type arg)
  {
    msg_.id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::object_tracking_messages::msg::FollowPersonState msg_;
};

class Init_FollowPersonState_state
{
public:
  Init_FollowPersonState_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FollowPersonState_id state(::object_tracking_messages::msg::FollowPersonState::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_FollowPersonState_id(msg_);
  }

private:
  ::object_tracking_messages::msg::FollowPersonState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::object_tracking_messages::msg::FollowPersonState>()
{
  return object_tracking_messages::msg::builder::Init_FollowPersonState_state();
}

}  // namespace object_tracking_messages

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__FOLLOW_PERSON_STATE__BUILDER_HPP_
