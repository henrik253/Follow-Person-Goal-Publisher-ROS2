// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from object_tracking_messages:msg/KeyPoint.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__KEY_POINT__TRAITS_HPP_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__KEY_POINT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "object_tracking_messages/msg/detail/key_point__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace object_tracking_messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const KeyPoint & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const KeyPoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const KeyPoint & msg, bool use_flow_style = false)
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
  const object_tracking_messages::msg::KeyPoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  object_tracking_messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use object_tracking_messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const object_tracking_messages::msg::KeyPoint & msg)
{
  return object_tracking_messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<object_tracking_messages::msg::KeyPoint>()
{
  return "object_tracking_messages::msg::KeyPoint";
}

template<>
inline const char * name<object_tracking_messages::msg::KeyPoint>()
{
  return "object_tracking_messages/msg/KeyPoint";
}

template<>
struct has_fixed_size<object_tracking_messages::msg::KeyPoint>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<object_tracking_messages::msg::KeyPoint>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<object_tracking_messages::msg::KeyPoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__KEY_POINT__TRAITS_HPP_
