// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from object_tracking_messages:msg/PersonDistance.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "object_tracking_messages/msg/detail/person_distance__rosidl_typesupport_introspection_c.h"
#include "object_tracking_messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "object_tracking_messages/msg/detail/person_distance__functions.h"
#include "object_tracking_messages/msg/detail/person_distance__struct.h"


// Include directives for member types
// Member `detected_persons`
#include "object_tracking_messages/msg/detected_persons.h"
// Member `detected_persons`
#include "object_tracking_messages/msg/detail/detected_persons__rosidl_typesupport_introspection_c.h"
// Member `distances`
// Member `real_world_coordinates`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__PersonDistance_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  object_tracking_messages__msg__PersonDistance__init(message_memory);
}

void object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__PersonDistance_fini_function(void * message_memory)
{
  object_tracking_messages__msg__PersonDistance__fini(message_memory);
}

size_t object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__size_function__PersonDistance__distances(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__get_const_function__PersonDistance__distances(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__get_function__PersonDistance__distances(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__fetch_function__PersonDistance__distances(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__get_const_function__PersonDistance__distances(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__assign_function__PersonDistance__distances(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__get_function__PersonDistance__distances(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__resize_function__PersonDistance__distances(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__size_function__PersonDistance__real_world_coordinates(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__get_const_function__PersonDistance__real_world_coordinates(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__get_function__PersonDistance__real_world_coordinates(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__fetch_function__PersonDistance__real_world_coordinates(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__get_const_function__PersonDistance__real_world_coordinates(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__assign_function__PersonDistance__real_world_coordinates(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__get_function__PersonDistance__real_world_coordinates(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__resize_function__PersonDistance__real_world_coordinates(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__PersonDistance_message_member_array[3] = {
  {
    "detected_persons",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_tracking_messages__msg__PersonDistance, detected_persons),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "distances",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_tracking_messages__msg__PersonDistance, distances),  // bytes offset in struct
    NULL,  // default value
    object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__size_function__PersonDistance__distances,  // size() function pointer
    object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__get_const_function__PersonDistance__distances,  // get_const(index) function pointer
    object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__get_function__PersonDistance__distances,  // get(index) function pointer
    object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__fetch_function__PersonDistance__distances,  // fetch(index, &value) function pointer
    object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__assign_function__PersonDistance__distances,  // assign(index, value) function pointer
    object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__resize_function__PersonDistance__distances  // resize(index) function pointer
  },
  {
    "real_world_coordinates",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_tracking_messages__msg__PersonDistance, real_world_coordinates),  // bytes offset in struct
    NULL,  // default value
    object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__size_function__PersonDistance__real_world_coordinates,  // size() function pointer
    object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__get_const_function__PersonDistance__real_world_coordinates,  // get_const(index) function pointer
    object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__get_function__PersonDistance__real_world_coordinates,  // get(index) function pointer
    object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__fetch_function__PersonDistance__real_world_coordinates,  // fetch(index, &value) function pointer
    object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__assign_function__PersonDistance__real_world_coordinates,  // assign(index, value) function pointer
    object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__resize_function__PersonDistance__real_world_coordinates  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__PersonDistance_message_members = {
  "object_tracking_messages__msg",  // message namespace
  "PersonDistance",  // message name
  3,  // number of fields
  sizeof(object_tracking_messages__msg__PersonDistance),
  object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__PersonDistance_message_member_array,  // message members
  object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__PersonDistance_init_function,  // function to initialize message memory (memory has to be allocated)
  object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__PersonDistance_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__PersonDistance_message_type_support_handle = {
  0,
  &object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__PersonDistance_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_object_tracking_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, object_tracking_messages, msg, PersonDistance)() {
  object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__PersonDistance_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, object_tracking_messages, msg, DetectedPersons)();
  if (!object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__PersonDistance_message_type_support_handle.typesupport_identifier) {
    object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__PersonDistance_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &object_tracking_messages__msg__PersonDistance__rosidl_typesupport_introspection_c__PersonDistance_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
