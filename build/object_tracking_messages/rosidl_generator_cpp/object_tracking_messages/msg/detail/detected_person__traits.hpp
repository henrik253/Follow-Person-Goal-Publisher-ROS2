// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from object_tracking_messages:msg/DetectedPerson.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSON__TRAITS_HPP_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSON__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "object_tracking_messages/msg/detail/detected_person__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'bbox'
#include "object_tracking_messages/msg/detail/bounding_box__traits.hpp"
// Member 'person_key_point'
#include "object_tracking_messages/msg/detail/person_key_point__traits.hpp"

namespace object_tracking_messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const DetectedPerson & msg,
  std::ostream & out)
{
  out << "{";
  // member: label
  {
    out << "label: ";
    rosidl_generator_traits::value_to_yaml(msg.label, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: bbox
  {
    out << "bbox: ";
    to_flow_style_yaml(msg.bbox, out);
    out << ", ";
  }

  // member: body_parts
  {
    if (msg.body_parts.size() == 0) {
      out << "body_parts: []";
    } else {
      out << "body_parts: [";
      size_t pending_items = msg.body_parts.size();
      for (auto item : msg.body_parts) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: person_key_point
  {
    if (msg.person_key_point.size() == 0) {
      out << "person_key_point: []";
    } else {
      out << "person_key_point: [";
      size_t pending_items = msg.person_key_point.size();
      for (auto item : msg.person_key_point) {
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
  const DetectedPerson & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: label
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "label: ";
    rosidl_generator_traits::value_to_yaml(msg.label, out);
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

  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: bbox
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bbox:\n";
    to_block_style_yaml(msg.bbox, out, indentation + 2);
  }

  // member: body_parts
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.body_parts.size() == 0) {
      out << "body_parts: []\n";
    } else {
      out << "body_parts:\n";
      for (auto item : msg.body_parts) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: person_key_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.person_key_point.size() == 0) {
      out << "person_key_point: []\n";
    } else {
      out << "person_key_point:\n";
      for (auto item : msg.person_key_point) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectedPerson & msg, bool use_flow_style = false)
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
  const object_tracking_messages::msg::DetectedPerson & msg,
  std::ostream & out, size_t indentation = 0)
{
  object_tracking_messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use object_tracking_messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const object_tracking_messages::msg::DetectedPerson & msg)
{
  return object_tracking_messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<object_tracking_messages::msg::DetectedPerson>()
{
  return "object_tracking_messages::msg::DetectedPerson";
}

template<>
inline const char * name<object_tracking_messages::msg::DetectedPerson>()
{
  return "object_tracking_messages/msg/DetectedPerson";
}

template<>
struct has_fixed_size<object_tracking_messages::msg::DetectedPerson>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<object_tracking_messages::msg::DetectedPerson>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<object_tracking_messages::msg::DetectedPerson>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSON__TRAITS_HPP_
