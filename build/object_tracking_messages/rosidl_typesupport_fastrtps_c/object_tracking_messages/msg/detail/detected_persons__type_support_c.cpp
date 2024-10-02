// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from object_tracking_messages:msg/DetectedPersons.idl
// generated code does not contain a copyright notice
#include "object_tracking_messages/msg/detail/detected_persons__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "object_tracking_messages/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "object_tracking_messages/msg/detail/detected_persons__struct.h"
#include "object_tracking_messages/msg/detail/detected_persons__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "object_tracking_messages/msg/detail/detected_person__functions.h"  // persons

// forward declare type support functions
size_t get_serialized_size_object_tracking_messages__msg__DetectedPerson(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_object_tracking_messages__msg__DetectedPerson(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, object_tracking_messages, msg, DetectedPerson)();


using _DetectedPersons__ros_msg_type = object_tracking_messages__msg__DetectedPersons;

static bool _DetectedPersons__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _DetectedPersons__ros_msg_type * ros_message = static_cast<const _DetectedPersons__ros_msg_type *>(untyped_ros_message);
  // Field name: persons
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, object_tracking_messages, msg, DetectedPerson
      )()->data);
    size_t size = ros_message->persons.size;
    auto array_ptr = ros_message->persons.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _DetectedPersons__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _DetectedPersons__ros_msg_type * ros_message = static_cast<_DetectedPersons__ros_msg_type *>(untyped_ros_message);
  // Field name: persons
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, object_tracking_messages, msg, DetectedPerson
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->persons.data) {
      object_tracking_messages__msg__DetectedPerson__Sequence__fini(&ros_message->persons);
    }
    if (!object_tracking_messages__msg__DetectedPerson__Sequence__init(&ros_message->persons, size)) {
      fprintf(stderr, "failed to create array for field 'persons'");
      return false;
    }
    auto array_ptr = ros_message->persons.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_object_tracking_messages
size_t get_serialized_size_object_tracking_messages__msg__DetectedPersons(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _DetectedPersons__ros_msg_type * ros_message = static_cast<const _DetectedPersons__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name persons
  {
    size_t array_size = ros_message->persons.size;
    auto array_ptr = ros_message->persons.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_object_tracking_messages__msg__DetectedPerson(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _DetectedPersons__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_object_tracking_messages__msg__DetectedPersons(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_object_tracking_messages
size_t max_serialized_size_object_tracking_messages__msg__DetectedPersons(
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

  // member: persons
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_object_tracking_messages__msg__DetectedPerson(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = object_tracking_messages__msg__DetectedPersons;
    is_plain =
      (
      offsetof(DataType, persons) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _DetectedPersons__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_object_tracking_messages__msg__DetectedPersons(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_DetectedPersons = {
  "object_tracking_messages::msg",
  "DetectedPersons",
  _DetectedPersons__cdr_serialize,
  _DetectedPersons__cdr_deserialize,
  _DetectedPersons__get_serialized_size,
  _DetectedPersons__max_serialized_size
};

static rosidl_message_type_support_t _DetectedPersons__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_DetectedPersons,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, object_tracking_messages, msg, DetectedPersons)() {
  return &_DetectedPersons__type_support;
}

#if defined(__cplusplus)
}
#endif
