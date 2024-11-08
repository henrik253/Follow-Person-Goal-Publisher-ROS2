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
// Member 'real_world_coordinates'
// Member 'nose_real_world_coordinates'
// Member 'left_eye_real_world_coordinates'
// Member 'right_eye_real_world_coordinates'
// Member 'left_ear_real_world_coordinates'
// Member 'right_ear_real_world_coordinates'
// Member 'left_shoulder_real_world_coordinates'
// Member 'right_shoulder_real_world_coordinates'
// Member 'left_elbow_real_world_coordinates'
// Member 'right_elbow_real_world_coordinates'
// Member 'left_wrist_real_world_coordinates'
// Member 'right_wrist_real_world_coordinates'
// Member 'left_hip_real_world_coordinates'
// Member 'right_hip_real_world_coordinates'
// Member 'left_knee_real_world_coordinates'
// Member 'right_knee_real_world_coordinates'
// Member 'left_ankle_real_world_coordinates'
// Member 'right_ankle_real_world_coordinates'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/PersonDistance in the package object_tracking_messages.
/**
  * PersonDistance.msg
 */
typedef struct object_tracking_messages__msg__PersonDistance
{
  object_tracking_messages__msg__DetectedPersons detected_persons;
  rosidl_runtime_c__float__Sequence distances;
  rosidl_runtime_c__float__Sequence real_world_coordinates;
  /// all the x,y,z values for all bodyparts detected on the image
  rosidl_runtime_c__float__Sequence nose_real_world_coordinates;
  rosidl_runtime_c__float__Sequence left_eye_real_world_coordinates;
  rosidl_runtime_c__float__Sequence right_eye_real_world_coordinates;
  rosidl_runtime_c__float__Sequence left_ear_real_world_coordinates;
  rosidl_runtime_c__float__Sequence right_ear_real_world_coordinates;
  rosidl_runtime_c__float__Sequence left_shoulder_real_world_coordinates;
  rosidl_runtime_c__float__Sequence right_shoulder_real_world_coordinates;
  rosidl_runtime_c__float__Sequence left_elbow_real_world_coordinates;
  rosidl_runtime_c__float__Sequence right_elbow_real_world_coordinates;
  rosidl_runtime_c__float__Sequence left_wrist_real_world_coordinates;
  rosidl_runtime_c__float__Sequence right_wrist_real_world_coordinates;
  rosidl_runtime_c__float__Sequence left_hip_real_world_coordinates;
  rosidl_runtime_c__float__Sequence right_hip_real_world_coordinates;
  rosidl_runtime_c__float__Sequence left_knee_real_world_coordinates;
  rosidl_runtime_c__float__Sequence right_knee_real_world_coordinates;
  rosidl_runtime_c__float__Sequence left_ankle_real_world_coordinates;
  rosidl_runtime_c__float__Sequence right_ankle_real_world_coordinates;
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
