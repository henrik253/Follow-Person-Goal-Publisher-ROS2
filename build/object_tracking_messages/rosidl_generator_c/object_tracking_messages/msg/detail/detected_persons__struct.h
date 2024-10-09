// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from object_tracking_messages:msg/DetectedPersons.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSONS__STRUCT_H_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSONS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'persons'
#include "object_tracking_messages/msg/detail/detected_person__struct.h"

/// Struct defined in msg/DetectedPersons in the package object_tracking_messages.
/**
  * DetectedPersons.msg
 */
typedef struct object_tracking_messages__msg__DetectedPersons
{
  object_tracking_messages__msg__DetectedPerson__Sequence persons;
} object_tracking_messages__msg__DetectedPersons;

// Struct for a sequence of object_tracking_messages__msg__DetectedPersons.
typedef struct object_tracking_messages__msg__DetectedPersons__Sequence
{
  object_tracking_messages__msg__DetectedPersons * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} object_tracking_messages__msg__DetectedPersons__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSONS__STRUCT_H_
