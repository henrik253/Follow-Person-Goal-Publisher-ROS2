// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from object_tracking_messages:msg/FollowPersonState.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__FOLLOW_PERSON_STATE__STRUCT_H_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__FOLLOW_PERSON_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'state'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/FollowPersonState in the package object_tracking_messages.
/**
  * FollowPersonState.msg
 */
typedef struct object_tracking_messages__msg__FollowPersonState
{
  rosidl_runtime_c__String state;
  int32_t id;
} object_tracking_messages__msg__FollowPersonState;

// Struct for a sequence of object_tracking_messages__msg__FollowPersonState.
typedef struct object_tracking_messages__msg__FollowPersonState__Sequence
{
  object_tracking_messages__msg__FollowPersonState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} object_tracking_messages__msg__FollowPersonState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__FOLLOW_PERSON_STATE__STRUCT_H_
