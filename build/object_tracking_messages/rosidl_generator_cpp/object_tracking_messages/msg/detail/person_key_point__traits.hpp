// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from object_tracking_messages:msg/PersonKeyPoint.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__PERSON_KEY_POINT__TRAITS_HPP_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__PERSON_KEY_POINT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "object_tracking_messages/msg/detail/person_key_point__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace object_tracking_messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const PersonKeyPoint & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PersonKeyPoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PersonKeyPoint & msg, bool use_flow_style = false)
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
  const object_tracking_messages::msg::PersonKeyPoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  object_tracking_messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use object_tracking_messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const object_tracking_messages::msg::PersonKeyPoint & msg)
{
  return object_tracking_messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<object_tracking_messages::msg::PersonKeyPoint>()
{
  return "object_tracking_messages::msg::PersonKeyPoint";
}

template<>
inline const char * name<object_tracking_messages::msg::PersonKeyPoint>()
{
  return "object_tracking_messages/msg/PersonKeyPoint";
}

template<>
struct has_fixed_size<object_tracking_messages::msg::PersonKeyPoint>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<object_tracking_messages::msg::PersonKeyPoint>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<object_tracking_messages::msg::PersonKeyPoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__PERSON_KEY_POINT__TRAITS_HPP_
