// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from object_tracking_messages:msg/DetectedPersons.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSONS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSONS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "object_tracking_messages/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "object_tracking_messages/msg/detail/detected_persons__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace object_tracking_messages
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_object_tracking_messages
cdr_serialize(
  const object_tracking_messages::msg::DetectedPersons & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_object_tracking_messages
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  object_tracking_messages::msg::DetectedPersons & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_object_tracking_messages
get_serialized_size(
  const object_tracking_messages::msg::DetectedPersons & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_object_tracking_messages
max_serialized_size_DetectedPersons(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace object_tracking_messages

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_object_tracking_messages
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, object_tracking_messages, msg, DetectedPersons)();

#ifdef __cplusplus
}
#endif

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSONS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_