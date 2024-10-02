// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from object_tracking_messages:msg/BoundingBox.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/BoundingBox in the package object_tracking_messages.
/**
  * BoundingBox.msg
 */
typedef struct object_tracking_messages__msg__BoundingBox
{
  int32_t x_min;
  int32_t y_min;
  int32_t x_max;
  int32_t y_max;
} object_tracking_messages__msg__BoundingBox;

// Struct for a sequence of object_tracking_messages__msg__BoundingBox.
typedef struct object_tracking_messages__msg__BoundingBox__Sequence
{
  object_tracking_messages__msg__BoundingBox * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} object_tracking_messages__msg__BoundingBox__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_
