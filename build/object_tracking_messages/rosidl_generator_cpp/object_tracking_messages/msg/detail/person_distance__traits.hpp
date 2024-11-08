// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from object_tracking_messages:msg/PersonDistance.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__PERSON_DISTANCE__TRAITS_HPP_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__PERSON_DISTANCE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "object_tracking_messages/msg/detail/person_distance__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'detected_persons'
#include "object_tracking_messages/msg/detail/detected_persons__traits.hpp"

namespace object_tracking_messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const PersonDistance & msg,
  std::ostream & out)
{
  out << "{";
  // member: detected_persons
  {
    out << "detected_persons: ";
    to_flow_style_yaml(msg.detected_persons, out);
    out << ", ";
  }

  // member: distances
  {
    if (msg.distances.size() == 0) {
      out << "distances: []";
    } else {
      out << "distances: [";
      size_t pending_items = msg.distances.size();
      for (auto item : msg.distances) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: real_world_coordinates
  {
    if (msg.real_world_coordinates.size() == 0) {
      out << "real_world_coordinates: []";
    } else {
      out << "real_world_coordinates: [";
      size_t pending_items = msg.real_world_coordinates.size();
      for (auto item : msg.real_world_coordinates) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: nose_real_world_coordinates
  {
    if (msg.nose_real_world_coordinates.size() == 0) {
      out << "nose_real_world_coordinates: []";
    } else {
      out << "nose_real_world_coordinates: [";
      size_t pending_items = msg.nose_real_world_coordinates.size();
      for (auto item : msg.nose_real_world_coordinates) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: left_eye_real_world_coordinates
  {
    if (msg.left_eye_real_world_coordinates.size() == 0) {
      out << "left_eye_real_world_coordinates: []";
    } else {
      out << "left_eye_real_world_coordinates: [";
      size_t pending_items = msg.left_eye_real_world_coordinates.size();
      for (auto item : msg.left_eye_real_world_coordinates) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: right_eye_real_world_coordinates
  {
    if (msg.right_eye_real_world_coordinates.size() == 0) {
      out << "right_eye_real_world_coordinates: []";
    } else {
      out << "right_eye_real_world_coordinates: [";
      size_t pending_items = msg.right_eye_real_world_coordinates.size();
      for (auto item : msg.right_eye_real_world_coordinates) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: left_ear_real_world_coordinates
  {
    if (msg.left_ear_real_world_coordinates.size() == 0) {
      out << "left_ear_real_world_coordinates: []";
    } else {
      out << "left_ear_real_world_coordinates: [";
      size_t pending_items = msg.left_ear_real_world_coordinates.size();
      for (auto item : msg.left_ear_real_world_coordinates) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: right_ear_real_world_coordinates
  {
    if (msg.right_ear_real_world_coordinates.size() == 0) {
      out << "right_ear_real_world_coordinates: []";
    } else {
      out << "right_ear_real_world_coordinates: [";
      size_t pending_items = msg.right_ear_real_world_coordinates.size();
      for (auto item : msg.right_ear_real_world_coordinates) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: left_shoulder_real_world_coordinates
  {
    if (msg.left_shoulder_real_world_coordinates.size() == 0) {
      out << "left_shoulder_real_world_coordinates: []";
    } else {
      out << "left_shoulder_real_world_coordinates: [";
      size_t pending_items = msg.left_shoulder_real_world_coordinates.size();
      for (auto item : msg.left_shoulder_real_world_coordinates) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: right_shoulder_real_world_coordinates
  {
    if (msg.right_shoulder_real_world_coordinates.size() == 0) {
      out << "right_shoulder_real_world_coordinates: []";
    } else {
      out << "right_shoulder_real_world_coordinates: [";
      size_t pending_items = msg.right_shoulder_real_world_coordinates.size();
      for (auto item : msg.right_shoulder_real_world_coordinates) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: left_elbow_real_world_coordinates
  {
    if (msg.left_elbow_real_world_coordinates.size() == 0) {
      out << "left_elbow_real_world_coordinates: []";
    } else {
      out << "left_elbow_real_world_coordinates: [";
      size_t pending_items = msg.left_elbow_real_world_coordinates.size();
      for (auto item : msg.left_elbow_real_world_coordinates) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: right_elbow_real_world_coordinates
  {
    if (msg.right_elbow_real_world_coordinates.size() == 0) {
      out << "right_elbow_real_world_coordinates: []";
    } else {
      out << "right_elbow_real_world_coordinates: [";
      size_t pending_items = msg.right_elbow_real_world_coordinates.size();
      for (auto item : msg.right_elbow_real_world_coordinates) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: left_wrist_real_world_coordinates
  {
    if (msg.left_wrist_real_world_coordinates.size() == 0) {
      out << "left_wrist_real_world_coordinates: []";
    } else {
      out << "left_wrist_real_world_coordinates: [";
      size_t pending_items = msg.left_wrist_real_world_coordinates.size();
      for (auto item : msg.left_wrist_real_world_coordinates) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: right_wrist_real_world_coordinates
  {
    if (msg.right_wrist_real_world_coordinates.size() == 0) {
      out << "right_wrist_real_world_coordinates: []";
    } else {
      out << "right_wrist_real_world_coordinates: [";
      size_t pending_items = msg.right_wrist_real_world_coordinates.size();
      for (auto item : msg.right_wrist_real_world_coordinates) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: left_hip_real_world_coordinates
  {
    if (msg.left_hip_real_world_coordinates.size() == 0) {
      out << "left_hip_real_world_coordinates: []";
    } else {
      out << "left_hip_real_world_coordinates: [";
      size_t pending_items = msg.left_hip_real_world_coordinates.size();
      for (auto item : msg.left_hip_real_world_coordinates) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: right_hip_real_world_coordinates
  {
    if (msg.right_hip_real_world_coordinates.size() == 0) {
      out << "right_hip_real_world_coordinates: []";
    } else {
      out << "right_hip_real_world_coordinates: [";
      size_t pending_items = msg.right_hip_real_world_coordinates.size();
      for (auto item : msg.right_hip_real_world_coordinates) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: left_knee_real_world_coordinates
  {
    if (msg.left_knee_real_world_coordinates.size() == 0) {
      out << "left_knee_real_world_coordinates: []";
    } else {
      out << "left_knee_real_world_coordinates: [";
      size_t pending_items = msg.left_knee_real_world_coordinates.size();
      for (auto item : msg.left_knee_real_world_coordinates) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: right_knee_real_world_coordinates
  {
    if (msg.right_knee_real_world_coordinates.size() == 0) {
      out << "right_knee_real_world_coordinates: []";
    } else {
      out << "right_knee_real_world_coordinates: [";
      size_t pending_items = msg.right_knee_real_world_coordinates.size();
      for (auto item : msg.right_knee_real_world_coordinates) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: left_ankle_real_world_coordinates
  {
    if (msg.left_ankle_real_world_coordinates.size() == 0) {
      out << "left_ankle_real_world_coordinates: []";
    } else {
      out << "left_ankle_real_world_coordinates: [";
      size_t pending_items = msg.left_ankle_real_world_coordinates.size();
      for (auto item : msg.left_ankle_real_world_coordinates) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: right_ankle_real_world_coordinates
  {
    if (msg.right_ankle_real_world_coordinates.size() == 0) {
      out << "right_ankle_real_world_coordinates: []";
    } else {
      out << "right_ankle_real_world_coordinates: [";
      size_t pending_items = msg.right_ankle_real_world_coordinates.size();
      for (auto item : msg.right_ankle_real_world_coordinates) {
        rosidl_generator_traits::value_to_yaml(item, out);
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
  const PersonDistance & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: detected_persons
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "detected_persons:\n";
    to_block_style_yaml(msg.detected_persons, out, indentation + 2);
  }

  // member: distances
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.distances.size() == 0) {
      out << "distances: []\n";
    } else {
      out << "distances:\n";
      for (auto item : msg.distances) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: real_world_coordinates
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.real_world_coordinates.size() == 0) {
      out << "real_world_coordinates: []\n";
    } else {
      out << "real_world_coordinates:\n";
      for (auto item : msg.real_world_coordinates) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: nose_real_world_coordinates
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.nose_real_world_coordinates.size() == 0) {
      out << "nose_real_world_coordinates: []\n";
    } else {
      out << "nose_real_world_coordinates:\n";
      for (auto item : msg.nose_real_world_coordinates) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: left_eye_real_world_coordinates
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.left_eye_real_world_coordinates.size() == 0) {
      out << "left_eye_real_world_coordinates: []\n";
    } else {
      out << "left_eye_real_world_coordinates:\n";
      for (auto item : msg.left_eye_real_world_coordinates) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: right_eye_real_world_coordinates
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.right_eye_real_world_coordinates.size() == 0) {
      out << "right_eye_real_world_coordinates: []\n";
    } else {
      out << "right_eye_real_world_coordinates:\n";
      for (auto item : msg.right_eye_real_world_coordinates) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: left_ear_real_world_coordinates
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.left_ear_real_world_coordinates.size() == 0) {
      out << "left_ear_real_world_coordinates: []\n";
    } else {
      out << "left_ear_real_world_coordinates:\n";
      for (auto item : msg.left_ear_real_world_coordinates) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: right_ear_real_world_coordinates
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.right_ear_real_world_coordinates.size() == 0) {
      out << "right_ear_real_world_coordinates: []\n";
    } else {
      out << "right_ear_real_world_coordinates:\n";
      for (auto item : msg.right_ear_real_world_coordinates) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: left_shoulder_real_world_coordinates
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.left_shoulder_real_world_coordinates.size() == 0) {
      out << "left_shoulder_real_world_coordinates: []\n";
    } else {
      out << "left_shoulder_real_world_coordinates:\n";
      for (auto item : msg.left_shoulder_real_world_coordinates) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: right_shoulder_real_world_coordinates
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.right_shoulder_real_world_coordinates.size() == 0) {
      out << "right_shoulder_real_world_coordinates: []\n";
    } else {
      out << "right_shoulder_real_world_coordinates:\n";
      for (auto item : msg.right_shoulder_real_world_coordinates) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: left_elbow_real_world_coordinates
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.left_elbow_real_world_coordinates.size() == 0) {
      out << "left_elbow_real_world_coordinates: []\n";
    } else {
      out << "left_elbow_real_world_coordinates:\n";
      for (auto item : msg.left_elbow_real_world_coordinates) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: right_elbow_real_world_coordinates
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.right_elbow_real_world_coordinates.size() == 0) {
      out << "right_elbow_real_world_coordinates: []\n";
    } else {
      out << "right_elbow_real_world_coordinates:\n";
      for (auto item : msg.right_elbow_real_world_coordinates) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: left_wrist_real_world_coordinates
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.left_wrist_real_world_coordinates.size() == 0) {
      out << "left_wrist_real_world_coordinates: []\n";
    } else {
      out << "left_wrist_real_world_coordinates:\n";
      for (auto item : msg.left_wrist_real_world_coordinates) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: right_wrist_real_world_coordinates
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.right_wrist_real_world_coordinates.size() == 0) {
      out << "right_wrist_real_world_coordinates: []\n";
    } else {
      out << "right_wrist_real_world_coordinates:\n";
      for (auto item : msg.right_wrist_real_world_coordinates) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: left_hip_real_world_coordinates
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.left_hip_real_world_coordinates.size() == 0) {
      out << "left_hip_real_world_coordinates: []\n";
    } else {
      out << "left_hip_real_world_coordinates:\n";
      for (auto item : msg.left_hip_real_world_coordinates) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: right_hip_real_world_coordinates
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.right_hip_real_world_coordinates.size() == 0) {
      out << "right_hip_real_world_coordinates: []\n";
    } else {
      out << "right_hip_real_world_coordinates:\n";
      for (auto item : msg.right_hip_real_world_coordinates) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: left_knee_real_world_coordinates
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.left_knee_real_world_coordinates.size() == 0) {
      out << "left_knee_real_world_coordinates: []\n";
    } else {
      out << "left_knee_real_world_coordinates:\n";
      for (auto item : msg.left_knee_real_world_coordinates) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: right_knee_real_world_coordinates
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.right_knee_real_world_coordinates.size() == 0) {
      out << "right_knee_real_world_coordinates: []\n";
    } else {
      out << "right_knee_real_world_coordinates:\n";
      for (auto item : msg.right_knee_real_world_coordinates) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: left_ankle_real_world_coordinates
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.left_ankle_real_world_coordinates.size() == 0) {
      out << "left_ankle_real_world_coordinates: []\n";
    } else {
      out << "left_ankle_real_world_coordinates:\n";
      for (auto item : msg.left_ankle_real_world_coordinates) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: right_ankle_real_world_coordinates
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.right_ankle_real_world_coordinates.size() == 0) {
      out << "right_ankle_real_world_coordinates: []\n";
    } else {
      out << "right_ankle_real_world_coordinates:\n";
      for (auto item : msg.right_ankle_real_world_coordinates) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PersonDistance & msg, bool use_flow_style = false)
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
  const object_tracking_messages::msg::PersonDistance & msg,
  std::ostream & out, size_t indentation = 0)
{
  object_tracking_messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use object_tracking_messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const object_tracking_messages::msg::PersonDistance & msg)
{
  return object_tracking_messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<object_tracking_messages::msg::PersonDistance>()
{
  return "object_tracking_messages::msg::PersonDistance";
}

template<>
inline const char * name<object_tracking_messages::msg::PersonDistance>()
{
  return "object_tracking_messages/msg/PersonDistance";
}

template<>
struct has_fixed_size<object_tracking_messages::msg::PersonDistance>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<object_tracking_messages::msg::PersonDistance>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<object_tracking_messages::msg::PersonDistance>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__PERSON_DISTANCE__TRAITS_HPP_
