// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from object_tracking_messages:msg/PersonDistance.idl
// generated code does not contain a copyright notice
#include "object_tracking_messages/msg/detail/person_distance__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "object_tracking_messages/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "object_tracking_messages/msg/detail/person_distance__struct.h"
#include "object_tracking_messages/msg/detail/person_distance__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "object_tracking_messages/msg/detail/detected_persons__functions.h"  // detected_persons
#include "rosidl_runtime_c/primitives_sequence.h"  // distances, left_ankle_real_world_coordinates, left_ear_real_world_coordinates, left_elbow_real_world_coordinates, left_eye_real_world_coordinates, left_hip_real_world_coordinates, left_knee_real_world_coordinates, left_shoulder_real_world_coordinates, left_wrist_real_world_coordinates, nose_real_world_coordinates, real_world_coordinates, right_ankle_real_world_coordinates, right_ear_real_world_coordinates, right_elbow_real_world_coordinates, right_eye_real_world_coordinates, right_hip_real_world_coordinates, right_knee_real_world_coordinates, right_shoulder_real_world_coordinates, right_wrist_real_world_coordinates
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // distances, left_ankle_real_world_coordinates, left_ear_real_world_coordinates, left_elbow_real_world_coordinates, left_eye_real_world_coordinates, left_hip_real_world_coordinates, left_knee_real_world_coordinates, left_shoulder_real_world_coordinates, left_wrist_real_world_coordinates, nose_real_world_coordinates, real_world_coordinates, right_ankle_real_world_coordinates, right_ear_real_world_coordinates, right_elbow_real_world_coordinates, right_eye_real_world_coordinates, right_hip_real_world_coordinates, right_knee_real_world_coordinates, right_shoulder_real_world_coordinates, right_wrist_real_world_coordinates

// forward declare type support functions
size_t get_serialized_size_object_tracking_messages__msg__DetectedPersons(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_object_tracking_messages__msg__DetectedPersons(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, object_tracking_messages, msg, DetectedPersons)();


using _PersonDistance__ros_msg_type = object_tracking_messages__msg__PersonDistance;

static bool _PersonDistance__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PersonDistance__ros_msg_type * ros_message = static_cast<const _PersonDistance__ros_msg_type *>(untyped_ros_message);
  // Field name: detected_persons
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, object_tracking_messages, msg, DetectedPersons
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->detected_persons, cdr))
    {
      return false;
    }
  }

  // Field name: distances
  {
    size_t size = ros_message->distances.size;
    auto array_ptr = ros_message->distances.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: real_world_coordinates
  {
    size_t size = ros_message->real_world_coordinates.size;
    auto array_ptr = ros_message->real_world_coordinates.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: nose_real_world_coordinates
  {
    size_t size = ros_message->nose_real_world_coordinates.size;
    auto array_ptr = ros_message->nose_real_world_coordinates.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: left_eye_real_world_coordinates
  {
    size_t size = ros_message->left_eye_real_world_coordinates.size;
    auto array_ptr = ros_message->left_eye_real_world_coordinates.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: right_eye_real_world_coordinates
  {
    size_t size = ros_message->right_eye_real_world_coordinates.size;
    auto array_ptr = ros_message->right_eye_real_world_coordinates.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: left_ear_real_world_coordinates
  {
    size_t size = ros_message->left_ear_real_world_coordinates.size;
    auto array_ptr = ros_message->left_ear_real_world_coordinates.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: right_ear_real_world_coordinates
  {
    size_t size = ros_message->right_ear_real_world_coordinates.size;
    auto array_ptr = ros_message->right_ear_real_world_coordinates.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: left_shoulder_real_world_coordinates
  {
    size_t size = ros_message->left_shoulder_real_world_coordinates.size;
    auto array_ptr = ros_message->left_shoulder_real_world_coordinates.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: right_shoulder_real_world_coordinates
  {
    size_t size = ros_message->right_shoulder_real_world_coordinates.size;
    auto array_ptr = ros_message->right_shoulder_real_world_coordinates.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: left_elbow_real_world_coordinates
  {
    size_t size = ros_message->left_elbow_real_world_coordinates.size;
    auto array_ptr = ros_message->left_elbow_real_world_coordinates.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: right_elbow_real_world_coordinates
  {
    size_t size = ros_message->right_elbow_real_world_coordinates.size;
    auto array_ptr = ros_message->right_elbow_real_world_coordinates.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: left_wrist_real_world_coordinates
  {
    size_t size = ros_message->left_wrist_real_world_coordinates.size;
    auto array_ptr = ros_message->left_wrist_real_world_coordinates.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: right_wrist_real_world_coordinates
  {
    size_t size = ros_message->right_wrist_real_world_coordinates.size;
    auto array_ptr = ros_message->right_wrist_real_world_coordinates.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: left_hip_real_world_coordinates
  {
    size_t size = ros_message->left_hip_real_world_coordinates.size;
    auto array_ptr = ros_message->left_hip_real_world_coordinates.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: right_hip_real_world_coordinates
  {
    size_t size = ros_message->right_hip_real_world_coordinates.size;
    auto array_ptr = ros_message->right_hip_real_world_coordinates.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: left_knee_real_world_coordinates
  {
    size_t size = ros_message->left_knee_real_world_coordinates.size;
    auto array_ptr = ros_message->left_knee_real_world_coordinates.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: right_knee_real_world_coordinates
  {
    size_t size = ros_message->right_knee_real_world_coordinates.size;
    auto array_ptr = ros_message->right_knee_real_world_coordinates.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: left_ankle_real_world_coordinates
  {
    size_t size = ros_message->left_ankle_real_world_coordinates.size;
    auto array_ptr = ros_message->left_ankle_real_world_coordinates.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: right_ankle_real_world_coordinates
  {
    size_t size = ros_message->right_ankle_real_world_coordinates.size;
    auto array_ptr = ros_message->right_ankle_real_world_coordinates.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _PersonDistance__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PersonDistance__ros_msg_type * ros_message = static_cast<_PersonDistance__ros_msg_type *>(untyped_ros_message);
  // Field name: detected_persons
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, object_tracking_messages, msg, DetectedPersons
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->detected_persons))
    {
      return false;
    }
  }

  // Field name: distances
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->distances.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->distances);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->distances, size)) {
      fprintf(stderr, "failed to create array for field 'distances'");
      return false;
    }
    auto array_ptr = ros_message->distances.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: real_world_coordinates
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->real_world_coordinates.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->real_world_coordinates);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->real_world_coordinates, size)) {
      fprintf(stderr, "failed to create array for field 'real_world_coordinates'");
      return false;
    }
    auto array_ptr = ros_message->real_world_coordinates.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: nose_real_world_coordinates
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->nose_real_world_coordinates.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->nose_real_world_coordinates);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->nose_real_world_coordinates, size)) {
      fprintf(stderr, "failed to create array for field 'nose_real_world_coordinates'");
      return false;
    }
    auto array_ptr = ros_message->nose_real_world_coordinates.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: left_eye_real_world_coordinates
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->left_eye_real_world_coordinates.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->left_eye_real_world_coordinates);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->left_eye_real_world_coordinates, size)) {
      fprintf(stderr, "failed to create array for field 'left_eye_real_world_coordinates'");
      return false;
    }
    auto array_ptr = ros_message->left_eye_real_world_coordinates.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: right_eye_real_world_coordinates
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->right_eye_real_world_coordinates.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->right_eye_real_world_coordinates);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->right_eye_real_world_coordinates, size)) {
      fprintf(stderr, "failed to create array for field 'right_eye_real_world_coordinates'");
      return false;
    }
    auto array_ptr = ros_message->right_eye_real_world_coordinates.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: left_ear_real_world_coordinates
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->left_ear_real_world_coordinates.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->left_ear_real_world_coordinates);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->left_ear_real_world_coordinates, size)) {
      fprintf(stderr, "failed to create array for field 'left_ear_real_world_coordinates'");
      return false;
    }
    auto array_ptr = ros_message->left_ear_real_world_coordinates.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: right_ear_real_world_coordinates
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->right_ear_real_world_coordinates.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->right_ear_real_world_coordinates);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->right_ear_real_world_coordinates, size)) {
      fprintf(stderr, "failed to create array for field 'right_ear_real_world_coordinates'");
      return false;
    }
    auto array_ptr = ros_message->right_ear_real_world_coordinates.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: left_shoulder_real_world_coordinates
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->left_shoulder_real_world_coordinates.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->left_shoulder_real_world_coordinates);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->left_shoulder_real_world_coordinates, size)) {
      fprintf(stderr, "failed to create array for field 'left_shoulder_real_world_coordinates'");
      return false;
    }
    auto array_ptr = ros_message->left_shoulder_real_world_coordinates.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: right_shoulder_real_world_coordinates
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->right_shoulder_real_world_coordinates.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->right_shoulder_real_world_coordinates);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->right_shoulder_real_world_coordinates, size)) {
      fprintf(stderr, "failed to create array for field 'right_shoulder_real_world_coordinates'");
      return false;
    }
    auto array_ptr = ros_message->right_shoulder_real_world_coordinates.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: left_elbow_real_world_coordinates
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->left_elbow_real_world_coordinates.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->left_elbow_real_world_coordinates);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->left_elbow_real_world_coordinates, size)) {
      fprintf(stderr, "failed to create array for field 'left_elbow_real_world_coordinates'");
      return false;
    }
    auto array_ptr = ros_message->left_elbow_real_world_coordinates.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: right_elbow_real_world_coordinates
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->right_elbow_real_world_coordinates.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->right_elbow_real_world_coordinates);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->right_elbow_real_world_coordinates, size)) {
      fprintf(stderr, "failed to create array for field 'right_elbow_real_world_coordinates'");
      return false;
    }
    auto array_ptr = ros_message->right_elbow_real_world_coordinates.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: left_wrist_real_world_coordinates
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->left_wrist_real_world_coordinates.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->left_wrist_real_world_coordinates);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->left_wrist_real_world_coordinates, size)) {
      fprintf(stderr, "failed to create array for field 'left_wrist_real_world_coordinates'");
      return false;
    }
    auto array_ptr = ros_message->left_wrist_real_world_coordinates.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: right_wrist_real_world_coordinates
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->right_wrist_real_world_coordinates.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->right_wrist_real_world_coordinates);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->right_wrist_real_world_coordinates, size)) {
      fprintf(stderr, "failed to create array for field 'right_wrist_real_world_coordinates'");
      return false;
    }
    auto array_ptr = ros_message->right_wrist_real_world_coordinates.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: left_hip_real_world_coordinates
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->left_hip_real_world_coordinates.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->left_hip_real_world_coordinates);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->left_hip_real_world_coordinates, size)) {
      fprintf(stderr, "failed to create array for field 'left_hip_real_world_coordinates'");
      return false;
    }
    auto array_ptr = ros_message->left_hip_real_world_coordinates.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: right_hip_real_world_coordinates
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->right_hip_real_world_coordinates.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->right_hip_real_world_coordinates);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->right_hip_real_world_coordinates, size)) {
      fprintf(stderr, "failed to create array for field 'right_hip_real_world_coordinates'");
      return false;
    }
    auto array_ptr = ros_message->right_hip_real_world_coordinates.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: left_knee_real_world_coordinates
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->left_knee_real_world_coordinates.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->left_knee_real_world_coordinates);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->left_knee_real_world_coordinates, size)) {
      fprintf(stderr, "failed to create array for field 'left_knee_real_world_coordinates'");
      return false;
    }
    auto array_ptr = ros_message->left_knee_real_world_coordinates.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: right_knee_real_world_coordinates
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->right_knee_real_world_coordinates.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->right_knee_real_world_coordinates);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->right_knee_real_world_coordinates, size)) {
      fprintf(stderr, "failed to create array for field 'right_knee_real_world_coordinates'");
      return false;
    }
    auto array_ptr = ros_message->right_knee_real_world_coordinates.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: left_ankle_real_world_coordinates
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->left_ankle_real_world_coordinates.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->left_ankle_real_world_coordinates);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->left_ankle_real_world_coordinates, size)) {
      fprintf(stderr, "failed to create array for field 'left_ankle_real_world_coordinates'");
      return false;
    }
    auto array_ptr = ros_message->left_ankle_real_world_coordinates.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: right_ankle_real_world_coordinates
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->right_ankle_real_world_coordinates.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->right_ankle_real_world_coordinates);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->right_ankle_real_world_coordinates, size)) {
      fprintf(stderr, "failed to create array for field 'right_ankle_real_world_coordinates'");
      return false;
    }
    auto array_ptr = ros_message->right_ankle_real_world_coordinates.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_object_tracking_messages
size_t get_serialized_size_object_tracking_messages__msg__PersonDistance(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PersonDistance__ros_msg_type * ros_message = static_cast<const _PersonDistance__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name detected_persons

  current_alignment += get_serialized_size_object_tracking_messages__msg__DetectedPersons(
    &(ros_message->detected_persons), current_alignment);
  // field.name distances
  {
    size_t array_size = ros_message->distances.size;
    auto array_ptr = ros_message->distances.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name real_world_coordinates
  {
    size_t array_size = ros_message->real_world_coordinates.size;
    auto array_ptr = ros_message->real_world_coordinates.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name nose_real_world_coordinates
  {
    size_t array_size = ros_message->nose_real_world_coordinates.size;
    auto array_ptr = ros_message->nose_real_world_coordinates.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name left_eye_real_world_coordinates
  {
    size_t array_size = ros_message->left_eye_real_world_coordinates.size;
    auto array_ptr = ros_message->left_eye_real_world_coordinates.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name right_eye_real_world_coordinates
  {
    size_t array_size = ros_message->right_eye_real_world_coordinates.size;
    auto array_ptr = ros_message->right_eye_real_world_coordinates.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name left_ear_real_world_coordinates
  {
    size_t array_size = ros_message->left_ear_real_world_coordinates.size;
    auto array_ptr = ros_message->left_ear_real_world_coordinates.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name right_ear_real_world_coordinates
  {
    size_t array_size = ros_message->right_ear_real_world_coordinates.size;
    auto array_ptr = ros_message->right_ear_real_world_coordinates.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name left_shoulder_real_world_coordinates
  {
    size_t array_size = ros_message->left_shoulder_real_world_coordinates.size;
    auto array_ptr = ros_message->left_shoulder_real_world_coordinates.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name right_shoulder_real_world_coordinates
  {
    size_t array_size = ros_message->right_shoulder_real_world_coordinates.size;
    auto array_ptr = ros_message->right_shoulder_real_world_coordinates.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name left_elbow_real_world_coordinates
  {
    size_t array_size = ros_message->left_elbow_real_world_coordinates.size;
    auto array_ptr = ros_message->left_elbow_real_world_coordinates.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name right_elbow_real_world_coordinates
  {
    size_t array_size = ros_message->right_elbow_real_world_coordinates.size;
    auto array_ptr = ros_message->right_elbow_real_world_coordinates.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name left_wrist_real_world_coordinates
  {
    size_t array_size = ros_message->left_wrist_real_world_coordinates.size;
    auto array_ptr = ros_message->left_wrist_real_world_coordinates.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name right_wrist_real_world_coordinates
  {
    size_t array_size = ros_message->right_wrist_real_world_coordinates.size;
    auto array_ptr = ros_message->right_wrist_real_world_coordinates.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name left_hip_real_world_coordinates
  {
    size_t array_size = ros_message->left_hip_real_world_coordinates.size;
    auto array_ptr = ros_message->left_hip_real_world_coordinates.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name right_hip_real_world_coordinates
  {
    size_t array_size = ros_message->right_hip_real_world_coordinates.size;
    auto array_ptr = ros_message->right_hip_real_world_coordinates.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name left_knee_real_world_coordinates
  {
    size_t array_size = ros_message->left_knee_real_world_coordinates.size;
    auto array_ptr = ros_message->left_knee_real_world_coordinates.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name right_knee_real_world_coordinates
  {
    size_t array_size = ros_message->right_knee_real_world_coordinates.size;
    auto array_ptr = ros_message->right_knee_real_world_coordinates.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name left_ankle_real_world_coordinates
  {
    size_t array_size = ros_message->left_ankle_real_world_coordinates.size;
    auto array_ptr = ros_message->left_ankle_real_world_coordinates.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name right_ankle_real_world_coordinates
  {
    size_t array_size = ros_message->right_ankle_real_world_coordinates.size;
    auto array_ptr = ros_message->right_ankle_real_world_coordinates.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _PersonDistance__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_object_tracking_messages__msg__PersonDistance(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_object_tracking_messages
size_t max_serialized_size_object_tracking_messages__msg__PersonDistance(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: detected_persons
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_object_tracking_messages__msg__DetectedPersons(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: distances
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: real_world_coordinates
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: nose_real_world_coordinates
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: left_eye_real_world_coordinates
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: right_eye_real_world_coordinates
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: left_ear_real_world_coordinates
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: right_ear_real_world_coordinates
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: left_shoulder_real_world_coordinates
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: right_shoulder_real_world_coordinates
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: left_elbow_real_world_coordinates
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: right_elbow_real_world_coordinates
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: left_wrist_real_world_coordinates
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: right_wrist_real_world_coordinates
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: left_hip_real_world_coordinates
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: right_hip_real_world_coordinates
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: left_knee_real_world_coordinates
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: right_knee_real_world_coordinates
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: left_ankle_real_world_coordinates
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: right_ankle_real_world_coordinates
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = object_tracking_messages__msg__PersonDistance;
    is_plain =
      (
      offsetof(DataType, right_ankle_real_world_coordinates) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _PersonDistance__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_object_tracking_messages__msg__PersonDistance(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_PersonDistance = {
  "object_tracking_messages::msg",
  "PersonDistance",
  _PersonDistance__cdr_serialize,
  _PersonDistance__cdr_deserialize,
  _PersonDistance__get_serialized_size,
  _PersonDistance__max_serialized_size
};

static rosidl_message_type_support_t _PersonDistance__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PersonDistance,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, object_tracking_messages, msg, PersonDistance)() {
  return &_PersonDistance__type_support;
}

#if defined(__cplusplus)
}
#endif
