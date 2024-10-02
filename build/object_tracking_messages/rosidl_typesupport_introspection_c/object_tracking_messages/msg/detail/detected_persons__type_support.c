// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from object_tracking_messages:msg/DetectedPersons.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "object_tracking_messages/msg/detail/detected_persons__rosidl_typesupport_introspection_c.h"
#include "object_tracking_messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "object_tracking_messages/msg/detail/detected_persons__functions.h"
#include "object_tracking_messages/msg/detail/detected_persons__struct.h"


// Include directives for member types
// Member `persons`
#include "object_tracking_messages/msg/detected_person.h"
// Member `persons`
#include "object_tracking_messages/msg/detail/detected_person__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__DetectedPersons_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  object_tracking_messages__msg__DetectedPersons__init(message_memory);
}

void object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__DetectedPersons_fini_function(void * message_memory)
{
  object_tracking_messages__msg__DetectedPersons__fini(message_memory);
}

size_t object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__size_function__DetectedPersons__persons(
  const void * untyped_member)
{
  const object_tracking_messages__msg__DetectedPerson__Sequence * member =
    (const object_tracking_messages__msg__DetectedPerson__Sequence *)(untyped_member);
  return member->size;
}

const void * object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__get_const_function__DetectedPersons__persons(
  const void * untyped_member, size_t index)
{
  const object_tracking_messages__msg__DetectedPerson__Sequence * member =
    (const object_tracking_messages__msg__DetectedPerson__Sequence *)(untyped_member);
  return &member->data[index];
}

void * object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__get_function__DetectedPersons__persons(
  void * untyped_member, size_t index)
{
  object_tracking_messages__msg__DetectedPerson__Sequence * member =
    (object_tracking_messages__msg__DetectedPerson__Sequence *)(untyped_member);
  return &member->data[index];
}

void object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__fetch_function__DetectedPersons__persons(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const object_tracking_messages__msg__DetectedPerson * item =
    ((const object_tracking_messages__msg__DetectedPerson *)
    object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__get_const_function__DetectedPersons__persons(untyped_member, index));
  object_tracking_messages__msg__DetectedPerson * value =
    (object_tracking_messages__msg__DetectedPerson *)(untyped_value);
  *value = *item;
}

void object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__assign_function__DetectedPersons__persons(
  void * untyped_member, size_t index, const void * untyped_value)
{
  object_tracking_messages__msg__DetectedPerson * item =
    ((object_tracking_messages__msg__DetectedPerson *)
    object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__get_function__DetectedPersons__persons(untyped_member, index));
  const object_tracking_messages__msg__DetectedPerson * value =
    (const object_tracking_messages__msg__DetectedPerson *)(untyped_value);
  *item = *value;
}

bool object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__resize_function__DetectedPersons__persons(
  void * untyped_member, size_t size)
{
  object_tracking_messages__msg__DetectedPerson__Sequence * member =
    (object_tracking_messages__msg__DetectedPerson__Sequence *)(untyped_member);
  object_tracking_messages__msg__DetectedPerson__Sequence__fini(member);
  return object_tracking_messages__msg__DetectedPerson__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__DetectedPersons_message_member_array[1] = {
  {
    "persons",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_tracking_messages__msg__DetectedPersons, persons),  // bytes offset in struct
    NULL,  // default value
    object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__size_function__DetectedPersons__persons,  // size() function pointer
    object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__get_const_function__DetectedPersons__persons,  // get_const(index) function pointer
    object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__get_function__DetectedPersons__persons,  // get(index) function pointer
    object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__fetch_function__DetectedPersons__persons,  // fetch(index, &value) function pointer
    object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__assign_function__DetectedPersons__persons,  // assign(index, value) function pointer
    object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__resize_function__DetectedPersons__persons  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__DetectedPersons_message_members = {
  "object_tracking_messages__msg",  // message namespace
  "DetectedPersons",  // message name
  1,  // number of fields
  sizeof(object_tracking_messages__msg__DetectedPersons),
  object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__DetectedPersons_message_member_array,  // message members
  object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__DetectedPersons_init_function,  // function to initialize message memory (memory has to be allocated)
  object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__DetectedPersons_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__DetectedPersons_message_type_support_handle = {
  0,
  &object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__DetectedPersons_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_object_tracking_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, object_tracking_messages, msg, DetectedPersons)() {
  object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__DetectedPersons_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, object_tracking_messages, msg, DetectedPerson)();
  if (!object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__DetectedPersons_message_type_support_handle.typesupport_identifier) {
    object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__DetectedPersons_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &object_tracking_messages__msg__DetectedPersons__rosidl_typesupport_introspection_c__DetectedPersons_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
