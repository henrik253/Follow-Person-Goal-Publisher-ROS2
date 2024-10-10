// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from object_tracking_messages:msg/PersonDistance.idl
// generated code does not contain a copyright notice
#include "object_tracking_messages/msg/detail/person_distance__rosidl_typesupport_fastrtps_cpp.hpp"
#include "object_tracking_messages/msg/detail/person_distance__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace object_tracking_messages
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const object_tracking_messages::msg::DetectedPersons &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  object_tracking_messages::msg::DetectedPersons &);
size_t get_serialized_size(
  const object_tracking_messages::msg::DetectedPersons &,
  size_t current_alignment);
size_t
max_serialized_size_DetectedPersons(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace object_tracking_messages


namespace object_tracking_messages
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_object_tracking_messages
cdr_serialize(
  const object_tracking_messages::msg::PersonDistance & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: detected_persons
  object_tracking_messages::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.detected_persons,
    cdr);
  // Member: distances
  {
    cdr << ros_message.distances;
  }
  // Member: real_world_coordinates
  {
    cdr << ros_message.real_world_coordinates;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_object_tracking_messages
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  object_tracking_messages::msg::PersonDistance & ros_message)
{
  // Member: detected_persons
  object_tracking_messages::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.detected_persons);

  // Member: distances
  {
    cdr >> ros_message.distances;
  }

  // Member: real_world_coordinates
  {
    cdr >> ros_message.real_world_coordinates;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_object_tracking_messages
get_serialized_size(
  const object_tracking_messages::msg::PersonDistance & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: detected_persons

  current_alignment +=
    object_tracking_messages::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.detected_persons, current_alignment);
  // Member: distances
  {
    size_t array_size = ros_message.distances.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.distances[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: real_world_coordinates
  {
    size_t array_size = ros_message.real_world_coordinates.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.real_world_coordinates[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_object_tracking_messages
max_serialized_size_PersonDistance(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: detected_persons
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        object_tracking_messages::msg::typesupport_fastrtps_cpp::max_serialized_size_DetectedPersons(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: distances
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: real_world_coordinates
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = object_tracking_messages::msg::PersonDistance;
    is_plain =
      (
      offsetof(DataType, real_world_coordinates) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _PersonDistance__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const object_tracking_messages::msg::PersonDistance *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _PersonDistance__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<object_tracking_messages::msg::PersonDistance *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _PersonDistance__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const object_tracking_messages::msg::PersonDistance *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _PersonDistance__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_PersonDistance(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _PersonDistance__callbacks = {
  "object_tracking_messages::msg",
  "PersonDistance",
  _PersonDistance__cdr_serialize,
  _PersonDistance__cdr_deserialize,
  _PersonDistance__get_serialized_size,
  _PersonDistance__max_serialized_size
};

static rosidl_message_type_support_t _PersonDistance__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_PersonDistance__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace object_tracking_messages

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_object_tracking_messages
const rosidl_message_type_support_t *
get_message_type_support_handle<object_tracking_messages::msg::PersonDistance>()
{
  return &object_tracking_messages::msg::typesupport_fastrtps_cpp::_PersonDistance__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, object_tracking_messages, msg, PersonDistance)() {
  return &object_tracking_messages::msg::typesupport_fastrtps_cpp::_PersonDistance__handle;
}

#ifdef __cplusplus
}
#endif
