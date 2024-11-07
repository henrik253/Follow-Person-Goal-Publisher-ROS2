// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from object_tracking_messages:msg/DetectedPerson.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "object_tracking_messages/msg/detail/detected_person__rosidl_typesupport_introspection_c.h"
#include "object_tracking_messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "object_tracking_messages/msg/detail/detected_person__functions.h"
#include "object_tracking_messages/msg/detail/detected_person__struct.h"


// Include directives for member types
// Member `label`
// Member `body_parts`
#include "rosidl_runtime_c/string_functions.h"
// Member `bbox`
#include "object_tracking_messages/msg/bounding_box.h"
// Member `bbox`
#include "object_tracking_messages/msg/detail/bounding_box__rosidl_typesupport_introspection_c.h"
// Member `person_key_point`
#include "object_tracking_messages/msg/person_key_point.h"
// Member `person_key_point`
#include "object_tracking_messages/msg/detail/person_key_point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__DetectedPerson_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  object_tracking_messages__msg__DetectedPerson__init(message_memory);
}

void object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__DetectedPerson_fini_function(void * message_memory)
{
  object_tracking_messages__msg__DetectedPerson__fini(message_memory);
}

size_t object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__size_function__DetectedPerson__body_parts(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__get_const_function__DetectedPerson__body_parts(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__get_function__DetectedPerson__body_parts(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__fetch_function__DetectedPerson__body_parts(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__get_const_function__DetectedPerson__body_parts(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__assign_function__DetectedPerson__body_parts(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__get_function__DetectedPerson__body_parts(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__resize_function__DetectedPerson__body_parts(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__size_function__DetectedPerson__person_key_point(
  const void * untyped_member)
{
  const object_tracking_messages__msg__PersonKeyPoint__Sequence * member =
    (const object_tracking_messages__msg__PersonKeyPoint__Sequence *)(untyped_member);
  return member->size;
}

const void * object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__get_const_function__DetectedPerson__person_key_point(
  const void * untyped_member, size_t index)
{
  const object_tracking_messages__msg__PersonKeyPoint__Sequence * member =
    (const object_tracking_messages__msg__PersonKeyPoint__Sequence *)(untyped_member);
  return &member->data[index];
}

void * object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__get_function__DetectedPerson__person_key_point(
  void * untyped_member, size_t index)
{
  object_tracking_messages__msg__PersonKeyPoint__Sequence * member =
    (object_tracking_messages__msg__PersonKeyPoint__Sequence *)(untyped_member);
  return &member->data[index];
}

void object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__fetch_function__DetectedPerson__person_key_point(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const object_tracking_messages__msg__PersonKeyPoint * item =
    ((const object_tracking_messages__msg__PersonKeyPoint *)
    object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__get_const_function__DetectedPerson__person_key_point(untyped_member, index));
  object_tracking_messages__msg__PersonKeyPoint * value =
    (object_tracking_messages__msg__PersonKeyPoint *)(untyped_value);
  *value = *item;
}

void object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__assign_function__DetectedPerson__person_key_point(
  void * untyped_member, size_t index, const void * untyped_value)
{
  object_tracking_messages__msg__PersonKeyPoint * item =
    ((object_tracking_messages__msg__PersonKeyPoint *)
    object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__get_function__DetectedPerson__person_key_point(untyped_member, index));
  const object_tracking_messages__msg__PersonKeyPoint * value =
    (const object_tracking_messages__msg__PersonKeyPoint *)(untyped_value);
  *item = *value;
}

bool object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__resize_function__DetectedPerson__person_key_point(
  void * untyped_member, size_t size)
{
  object_tracking_messages__msg__PersonKeyPoint__Sequence * member =
    (object_tracking_messages__msg__PersonKeyPoint__Sequence *)(untyped_member);
  object_tracking_messages__msg__PersonKeyPoint__Sequence__fini(member);
  return object_tracking_messages__msg__PersonKeyPoint__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__DetectedPerson_message_member_array[6] = {
  {
    "label",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_tracking_messages__msg__DetectedPerson, label),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "confidence",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_tracking_messages__msg__DetectedPerson, confidence),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_tracking_messages__msg__DetectedPerson, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bbox",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_tracking_messages__msg__DetectedPerson, bbox),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "body_parts",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_tracking_messages__msg__DetectedPerson, body_parts),  // bytes offset in struct
    NULL,  // default value
    object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__size_function__DetectedPerson__body_parts,  // size() function pointer
    object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__get_const_function__DetectedPerson__body_parts,  // get_const(index) function pointer
    object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__get_function__DetectedPerson__body_parts,  // get(index) function pointer
    object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__fetch_function__DetectedPerson__body_parts,  // fetch(index, &value) function pointer
    object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__assign_function__DetectedPerson__body_parts,  // assign(index, value) function pointer
    object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__resize_function__DetectedPerson__body_parts  // resize(index) function pointer
  },
  {
    "person_key_point",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_tracking_messages__msg__DetectedPerson, person_key_point),  // bytes offset in struct
    NULL,  // default value
    object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__size_function__DetectedPerson__person_key_point,  // size() function pointer
    object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__get_const_function__DetectedPerson__person_key_point,  // get_const(index) function pointer
    object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__get_function__DetectedPerson__person_key_point,  // get(index) function pointer
    object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__fetch_function__DetectedPerson__person_key_point,  // fetch(index, &value) function pointer
    object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__assign_function__DetectedPerson__person_key_point,  // assign(index, value) function pointer
    object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__resize_function__DetectedPerson__person_key_point  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__DetectedPerson_message_members = {
  "object_tracking_messages__msg",  // message namespace
  "DetectedPerson",  // message name
  6,  // number of fields
  sizeof(object_tracking_messages__msg__DetectedPerson),
  object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__DetectedPerson_message_member_array,  // message members
  object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__DetectedPerson_init_function,  // function to initialize message memory (memory has to be allocated)
  object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__DetectedPerson_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__DetectedPerson_message_type_support_handle = {
  0,
  &object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__DetectedPerson_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_object_tracking_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, object_tracking_messages, msg, DetectedPerson)() {
  object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__DetectedPerson_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, object_tracking_messages, msg, BoundingBox)();
  object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__DetectedPerson_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, object_tracking_messages, msg, PersonKeyPoint)();
  if (!object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__DetectedPerson_message_type_support_handle.typesupport_identifier) {
    object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__DetectedPerson_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &object_tracking_messages__msg__DetectedPerson__rosidl_typesupport_introspection_c__DetectedPerson_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
