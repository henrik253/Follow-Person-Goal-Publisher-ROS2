// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from object_tracking_messages:msg/PersonKeyPoint.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "object_tracking_messages/msg/detail/person_key_point__rosidl_typesupport_introspection_c.h"
#include "object_tracking_messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "object_tracking_messages/msg/detail/person_key_point__functions.h"
#include "object_tracking_messages/msg/detail/person_key_point__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void object_tracking_messages__msg__PersonKeyPoint__rosidl_typesupport_introspection_c__PersonKeyPoint_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  object_tracking_messages__msg__PersonKeyPoint__init(message_memory);
}

void object_tracking_messages__msg__PersonKeyPoint__rosidl_typesupport_introspection_c__PersonKeyPoint_fini_function(void * message_memory)
{
  object_tracking_messages__msg__PersonKeyPoint__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember object_tracking_messages__msg__PersonKeyPoint__rosidl_typesupport_introspection_c__PersonKeyPoint_message_member_array[3] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_tracking_messages__msg__PersonKeyPoint, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_tracking_messages__msg__PersonKeyPoint, y),  // bytes offset in struct
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
    offsetof(object_tracking_messages__msg__PersonKeyPoint, confidence),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers object_tracking_messages__msg__PersonKeyPoint__rosidl_typesupport_introspection_c__PersonKeyPoint_message_members = {
  "object_tracking_messages__msg",  // message namespace
  "PersonKeyPoint",  // message name
  3,  // number of fields
  sizeof(object_tracking_messages__msg__PersonKeyPoint),
  object_tracking_messages__msg__PersonKeyPoint__rosidl_typesupport_introspection_c__PersonKeyPoint_message_member_array,  // message members
  object_tracking_messages__msg__PersonKeyPoint__rosidl_typesupport_introspection_c__PersonKeyPoint_init_function,  // function to initialize message memory (memory has to be allocated)
  object_tracking_messages__msg__PersonKeyPoint__rosidl_typesupport_introspection_c__PersonKeyPoint_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t object_tracking_messages__msg__PersonKeyPoint__rosidl_typesupport_introspection_c__PersonKeyPoint_message_type_support_handle = {
  0,
  &object_tracking_messages__msg__PersonKeyPoint__rosidl_typesupport_introspection_c__PersonKeyPoint_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_object_tracking_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, object_tracking_messages, msg, PersonKeyPoint)() {
  if (!object_tracking_messages__msg__PersonKeyPoint__rosidl_typesupport_introspection_c__PersonKeyPoint_message_type_support_handle.typesupport_identifier) {
    object_tracking_messages__msg__PersonKeyPoint__rosidl_typesupport_introspection_c__PersonKeyPoint_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &object_tracking_messages__msg__PersonKeyPoint__rosidl_typesupport_introspection_c__PersonKeyPoint_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
