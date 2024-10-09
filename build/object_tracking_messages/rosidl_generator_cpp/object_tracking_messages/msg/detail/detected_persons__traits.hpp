// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from object_tracking_messages:msg/DetectedPersons.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSONS__TRAITS_HPP_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSONS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "object_tracking_messages/msg/detail/detected_persons__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'persons'
#include "object_tracking_messages/msg/detail/detected_person__traits.hpp"

namespace object_tracking_messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const DetectedPersons & msg,
  std::ostream & out)
{
  out << "{";
  // member: persons
  {
    if (msg.persons.size() == 0) {
      out << "persons: []";
    } else {
      out << "persons: [";
      size_t pending_items = msg.persons.size();
      for (auto item : msg.persons) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DetectedPersons & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: persons
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.persons.size() == 0) {
      out << "persons: []\n";
    } else {
      out << "persons:\n";
      for (auto item : msg.persons) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectedPersons & msg, bool use_flow_style = false)
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
  const object_tracking_messages::msg::DetectedPersons & msg,
  std::ostream & out, size_t indentation = 0)
{
  object_tracking_messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use object_tracking_messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const object_tracking_messages::msg::DetectedPersons & msg)
{
  return object_tracking_messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<object_tracking_messages::msg::DetectedPersons>()
{
  return "object_tracking_messages::msg::DetectedPersons";
}

template<>
inline const char * name<object_tracking_messages::msg::DetectedPersons>()
{
  return "object_tracking_messages/msg/DetectedPersons";
}

template<>
struct has_fixed_size<object_tracking_messages::msg::DetectedPersons>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<object_tracking_messages::msg::DetectedPersons>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<object_tracking_messages::msg::DetectedPersons>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSONS__TRAITS_HPP_
