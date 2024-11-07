// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from object_tracking_messages:msg/PersonKeyPoint.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__PERSON_KEY_POINT__STRUCT_H_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__PERSON_KEY_POINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/PersonKeyPoint in the package object_tracking_messages.
/**
  * PersonKeyPoint.msg
 */
typedef struct object_tracking_messages__msg__PersonKeyPoint
{
  float x;
  float y;
  float confidence;
} object_tracking_messages__msg__PersonKeyPoint;

// Struct for a sequence of object_tracking_messages__msg__PersonKeyPoint.
typedef struct object_tracking_messages__msg__PersonKeyPoint__Sequence
{
  object_tracking_messages__msg__PersonKeyPoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} object_tracking_messages__msg__PersonKeyPoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__PERSON_KEY_POINT__STRUCT_H_
