// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from object_tracking_messages:msg/FollowPersonState.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__FOLLOW_PERSON_STATE__TRAITS_HPP_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__FOLLOW_PERSON_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "object_tracking_messages/msg/detail/follow_person_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace object_tracking_messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const FollowPersonState & msg,
  std::ostream & out)
{
  out << "{";
  // member: state
  {
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << ", ";
  }

  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FollowPersonState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << "\n";
  }

  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FollowPersonState & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace object_tracking_messages

namespace rosidl_generator_traits
{

[[deprecated("use object_tracking_messages::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const object_tracking_messages::msg::FollowPersonState & msg,
  std::ostream & out, size_t indentation = 0)
{
  object_tracking_messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use object_tracking_messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const object_tracking_messages::msg::FollowPersonState & msg)
{
  return object_tracking_messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<object_tracking_messages::msg::FollowPersonState>()
{
  return "object_tracking_messages::msg::FollowPersonState";
}

template<>
inline const char * name<object_tracking_messages::msg::FollowPersonState>()
{
  return "object_tracking_messages/msg/FollowPersonState";
}

template<>
struct has_fixed_size<object_tracking_messages::msg::FollowPersonState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<object_tracking_messages::msg::FollowPersonState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<object_tracking_messages::msg::FollowPersonState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__FOLLOW_PERSON_STATE__TRAITS_HPP_
