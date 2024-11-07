// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from object_tracking_messages:msg/KeyPoint.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__KEY_POINT__STRUCT_H_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__KEY_POINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/KeyPoint in the package object_tracking_messages.
typedef struct object_tracking_messages__msg__KeyPoint
{
  uint8_t structure_needs_at_least_one_member;
} object_tracking_messages__msg__KeyPoint;

// Struct for a sequence of object_tracking_messages__msg__KeyPoint.
typedef struct object_tracking_messages__msg__KeyPoint__Sequence
{
  object_tracking_messages__msg__KeyPoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} object_tracking_messages__msg__KeyPoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__KEY_POINT__STRUCT_H_
