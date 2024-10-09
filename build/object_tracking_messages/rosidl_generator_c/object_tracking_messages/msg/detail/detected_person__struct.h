// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from object_tracking_messages:msg/DetectedPerson.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSON__STRUCT_H_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSON__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'bbox'
#include "object_tracking_messages/msg/detail/bounding_box__struct.h"

/// Struct defined in msg/DetectedPerson in the package object_tracking_messages.
/**
  * Detected Person.msg
 */
typedef struct object_tracking_messages__msg__DetectedPerson
{
  float confidence;
  int32_t id;
  object_tracking_messages__msg__BoundingBox bbox;
} object_tracking_messages__msg__DetectedPerson;

// Struct for a sequence of object_tracking_messages__msg__DetectedPerson.
typedef struct object_tracking_messages__msg__DetectedPerson__Sequence
{
  object_tracking_messages__msg__DetectedPerson * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} object_tracking_messages__msg__DetectedPerson__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSON__STRUCT_H_
