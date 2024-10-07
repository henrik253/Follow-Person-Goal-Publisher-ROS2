// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from object_tracking_messages:msg/PersonDistance.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__PERSON_DISTANCE__STRUCT_H_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__PERSON_DISTANCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'detected_persons'
#include "object_tracking_messages/msg/detail/detected_persons__struct.h"
// Member 'distances'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/PersonDistance in the package object_tracking_messages.
/**
  * PersonDistance.msg
 */
typedef struct object_tracking_messages__msg__PersonDistance
{
  object_tracking_messages__msg__DetectedPersons detected_persons;
  rosidl_runtime_c__float__Sequence distances;
} object_tracking_messages__msg__PersonDistance;

// Struct for a sequence of object_tracking_messages__msg__PersonDistance.
typedef struct object_tracking_messages__msg__PersonDistance__Sequence
{
  object_tracking_messages__msg__PersonDistance * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} object_tracking_messages__msg__PersonDistance__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__PERSON_DISTANCE__STRUCT_H_
