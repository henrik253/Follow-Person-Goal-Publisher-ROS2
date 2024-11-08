// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from object_tracking_messages:msg/PersonDistance.idl
// generated code does not contain a copyright notice
#include "object_tracking_messages/msg/detail/person_distance__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `detected_persons`
#include "object_tracking_messages/msg/detail/detected_persons__functions.h"
// Member `distances`
// Member `real_world_coordinates`
// Member `nose_real_world_coordinates`
// Member `left_eye_real_world_coordinates`
// Member `right_eye_real_world_coordinates`
// Member `left_ear_real_world_coordinates`
// Member `right_ear_real_world_coordinates`
// Member `left_shoulder_real_world_coordinates`
// Member `right_shoulder_real_world_coordinates`
// Member `left_elbow_real_world_coordinates`
// Member `right_elbow_real_world_coordinates`
// Member `left_wrist_real_world_coordinates`
// Member `right_wrist_real_world_coordinates`
// Member `left_hip_real_world_coordinates`
// Member `right_hip_real_world_coordinates`
// Member `left_knee_real_world_coordinates`
// Member `right_knee_real_world_coordinates`
// Member `left_ankle_real_world_coordinates`
// Member `right_ankle_real_world_coordinates`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
object_tracking_messages__msg__PersonDistance__init(object_tracking_messages__msg__PersonDistance * msg)
{
  if (!msg) {
    return false;
  }
  // detected_persons
  if (!object_tracking_messages__msg__DetectedPersons__init(&msg->detected_persons)) {
    object_tracking_messages__msg__PersonDistance__fini(msg);
    return false;
  }
  // distances
  if (!rosidl_runtime_c__float__Sequence__init(&msg->distances, 0)) {
    object_tracking_messages__msg__PersonDistance__fini(msg);
    return false;
  }
  // real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__init(&msg->real_world_coordinates, 0)) {
    object_tracking_messages__msg__PersonDistance__fini(msg);
    return false;
  }
  // nose_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__init(&msg->nose_real_world_coordinates, 0)) {
    object_tracking_messages__msg__PersonDistance__fini(msg);
    return false;
  }
  // left_eye_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__init(&msg->left_eye_real_world_coordinates, 0)) {
    object_tracking_messages__msg__PersonDistance__fini(msg);
    return false;
  }
  // right_eye_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__init(&msg->right_eye_real_world_coordinates, 0)) {
    object_tracking_messages__msg__PersonDistance__fini(msg);
    return false;
  }
  // left_ear_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__init(&msg->left_ear_real_world_coordinates, 0)) {
    object_tracking_messages__msg__PersonDistance__fini(msg);
    return false;
  }
  // right_ear_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__init(&msg->right_ear_real_world_coordinates, 0)) {
    object_tracking_messages__msg__PersonDistance__fini(msg);
    return false;
  }
  // left_shoulder_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__init(&msg->left_shoulder_real_world_coordinates, 0)) {
    object_tracking_messages__msg__PersonDistance__fini(msg);
    return false;
  }
  // right_shoulder_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__init(&msg->right_shoulder_real_world_coordinates, 0)) {
    object_tracking_messages__msg__PersonDistance__fini(msg);
    return false;
  }
  // left_elbow_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__init(&msg->left_elbow_real_world_coordinates, 0)) {
    object_tracking_messages__msg__PersonDistance__fini(msg);
    return false;
  }
  // right_elbow_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__init(&msg->right_elbow_real_world_coordinates, 0)) {
    object_tracking_messages__msg__PersonDistance__fini(msg);
    return false;
  }
  // left_wrist_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__init(&msg->left_wrist_real_world_coordinates, 0)) {
    object_tracking_messages__msg__PersonDistance__fini(msg);
    return false;
  }
  // right_wrist_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__init(&msg->right_wrist_real_world_coordinates, 0)) {
    object_tracking_messages__msg__PersonDistance__fini(msg);
    return false;
  }
  // left_hip_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__init(&msg->left_hip_real_world_coordinates, 0)) {
    object_tracking_messages__msg__PersonDistance__fini(msg);
    return false;
  }
  // right_hip_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__init(&msg->right_hip_real_world_coordinates, 0)) {
    object_tracking_messages__msg__PersonDistance__fini(msg);
    return false;
  }
  // left_knee_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__init(&msg->left_knee_real_world_coordinates, 0)) {
    object_tracking_messages__msg__PersonDistance__fini(msg);
    return false;
  }
  // right_knee_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__init(&msg->right_knee_real_world_coordinates, 0)) {
    object_tracking_messages__msg__PersonDistance__fini(msg);
    return false;
  }
  // left_ankle_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__init(&msg->left_ankle_real_world_coordinates, 0)) {
    object_tracking_messages__msg__PersonDistance__fini(msg);
    return false;
  }
  // right_ankle_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__init(&msg->right_ankle_real_world_coordinates, 0)) {
    object_tracking_messages__msg__PersonDistance__fini(msg);
    return false;
  }
  return true;
}

void
object_tracking_messages__msg__PersonDistance__fini(object_tracking_messages__msg__PersonDistance * msg)
{
  if (!msg) {
    return;
  }
  // detected_persons
  object_tracking_messages__msg__DetectedPersons__fini(&msg->detected_persons);
  // distances
  rosidl_runtime_c__float__Sequence__fini(&msg->distances);
  // real_world_coordinates
  rosidl_runtime_c__float__Sequence__fini(&msg->real_world_coordinates);
  // nose_real_world_coordinates
  rosidl_runtime_c__float__Sequence__fini(&msg->nose_real_world_coordinates);
  // left_eye_real_world_coordinates
  rosidl_runtime_c__float__Sequence__fini(&msg->left_eye_real_world_coordinates);
  // right_eye_real_world_coordinates
  rosidl_runtime_c__float__Sequence__fini(&msg->right_eye_real_world_coordinates);
  // left_ear_real_world_coordinates
  rosidl_runtime_c__float__Sequence__fini(&msg->left_ear_real_world_coordinates);
  // right_ear_real_world_coordinates
  rosidl_runtime_c__float__Sequence__fini(&msg->right_ear_real_world_coordinates);
  // left_shoulder_real_world_coordinates
  rosidl_runtime_c__float__Sequence__fini(&msg->left_shoulder_real_world_coordinates);
  // right_shoulder_real_world_coordinates
  rosidl_runtime_c__float__Sequence__fini(&msg->right_shoulder_real_world_coordinates);
  // left_elbow_real_world_coordinates
  rosidl_runtime_c__float__Sequence__fini(&msg->left_elbow_real_world_coordinates);
  // right_elbow_real_world_coordinates
  rosidl_runtime_c__float__Sequence__fini(&msg->right_elbow_real_world_coordinates);
  // left_wrist_real_world_coordinates
  rosidl_runtime_c__float__Sequence__fini(&msg->left_wrist_real_world_coordinates);
  // right_wrist_real_world_coordinates
  rosidl_runtime_c__float__Sequence__fini(&msg->right_wrist_real_world_coordinates);
  // left_hip_real_world_coordinates
  rosidl_runtime_c__float__Sequence__fini(&msg->left_hip_real_world_coordinates);
  // right_hip_real_world_coordinates
  rosidl_runtime_c__float__Sequence__fini(&msg->right_hip_real_world_coordinates);
  // left_knee_real_world_coordinates
  rosidl_runtime_c__float__Sequence__fini(&msg->left_knee_real_world_coordinates);
  // right_knee_real_world_coordinates
  rosidl_runtime_c__float__Sequence__fini(&msg->right_knee_real_world_coordinates);
  // left_ankle_real_world_coordinates
  rosidl_runtime_c__float__Sequence__fini(&msg->left_ankle_real_world_coordinates);
  // right_ankle_real_world_coordinates
  rosidl_runtime_c__float__Sequence__fini(&msg->right_ankle_real_world_coordinates);
}

bool
object_tracking_messages__msg__PersonDistance__are_equal(const object_tracking_messages__msg__PersonDistance * lhs, const object_tracking_messages__msg__PersonDistance * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // detected_persons
  if (!object_tracking_messages__msg__DetectedPersons__are_equal(
      &(lhs->detected_persons), &(rhs->detected_persons)))
  {
    return false;
  }
  // distances
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->distances), &(rhs->distances)))
  {
    return false;
  }
  // real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->real_world_coordinates), &(rhs->real_world_coordinates)))
  {
    return false;
  }
  // nose_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->nose_real_world_coordinates), &(rhs->nose_real_world_coordinates)))
  {
    return false;
  }
  // left_eye_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->left_eye_real_world_coordinates), &(rhs->left_eye_real_world_coordinates)))
  {
    return false;
  }
  // right_eye_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->right_eye_real_world_coordinates), &(rhs->right_eye_real_world_coordinates)))
  {
    return false;
  }
  // left_ear_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->left_ear_real_world_coordinates), &(rhs->left_ear_real_world_coordinates)))
  {
    return false;
  }
  // right_ear_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->right_ear_real_world_coordinates), &(rhs->right_ear_real_world_coordinates)))
  {
    return false;
  }
  // left_shoulder_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->left_shoulder_real_world_coordinates), &(rhs->left_shoulder_real_world_coordinates)))
  {
    return false;
  }
  // right_shoulder_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->right_shoulder_real_world_coordinates), &(rhs->right_shoulder_real_world_coordinates)))
  {
    return false;
  }
  // left_elbow_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->left_elbow_real_world_coordinates), &(rhs->left_elbow_real_world_coordinates)))
  {
    return false;
  }
  // right_elbow_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->right_elbow_real_world_coordinates), &(rhs->right_elbow_real_world_coordinates)))
  {
    return false;
  }
  // left_wrist_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->left_wrist_real_world_coordinates), &(rhs->left_wrist_real_world_coordinates)))
  {
    return false;
  }
  // right_wrist_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->right_wrist_real_world_coordinates), &(rhs->right_wrist_real_world_coordinates)))
  {
    return false;
  }
  // left_hip_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->left_hip_real_world_coordinates), &(rhs->left_hip_real_world_coordinates)))
  {
    return false;
  }
  // right_hip_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->right_hip_real_world_coordinates), &(rhs->right_hip_real_world_coordinates)))
  {
    return false;
  }
  // left_knee_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->left_knee_real_world_coordinates), &(rhs->left_knee_real_world_coordinates)))
  {
    return false;
  }
  // right_knee_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->right_knee_real_world_coordinates), &(rhs->right_knee_real_world_coordinates)))
  {
    return false;
  }
  // left_ankle_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->left_ankle_real_world_coordinates), &(rhs->left_ankle_real_world_coordinates)))
  {
    return false;
  }
  // right_ankle_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->right_ankle_real_world_coordinates), &(rhs->right_ankle_real_world_coordinates)))
  {
    return false;
  }
  return true;
}

bool
object_tracking_messages__msg__PersonDistance__copy(
  const object_tracking_messages__msg__PersonDistance * input,
  object_tracking_messages__msg__PersonDistance * output)
{
  if (!input || !output) {
    return false;
  }
  // detected_persons
  if (!object_tracking_messages__msg__DetectedPersons__copy(
      &(input->detected_persons), &(output->detected_persons)))
  {
    return false;
  }
  // distances
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->distances), &(output->distances)))
  {
    return false;
  }
  // real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->real_world_coordinates), &(output->real_world_coordinates)))
  {
    return false;
  }
  // nose_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->nose_real_world_coordinates), &(output->nose_real_world_coordinates)))
  {
    return false;
  }
  // left_eye_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->left_eye_real_world_coordinates), &(output->left_eye_real_world_coordinates)))
  {
    return false;
  }
  // right_eye_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->right_eye_real_world_coordinates), &(output->right_eye_real_world_coordinates)))
  {
    return false;
  }
  // left_ear_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->left_ear_real_world_coordinates), &(output->left_ear_real_world_coordinates)))
  {
    return false;
  }
  // right_ear_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->right_ear_real_world_coordinates), &(output->right_ear_real_world_coordinates)))
  {
    return false;
  }
  // left_shoulder_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->left_shoulder_real_world_coordinates), &(output->left_shoulder_real_world_coordinates)))
  {
    return false;
  }
  // right_shoulder_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->right_shoulder_real_world_coordinates), &(output->right_shoulder_real_world_coordinates)))
  {
    return false;
  }
  // left_elbow_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->left_elbow_real_world_coordinates), &(output->left_elbow_real_world_coordinates)))
  {
    return false;
  }
  // right_elbow_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->right_elbow_real_world_coordinates), &(output->right_elbow_real_world_coordinates)))
  {
    return false;
  }
  // left_wrist_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->left_wrist_real_world_coordinates), &(output->left_wrist_real_world_coordinates)))
  {
    return false;
  }
  // right_wrist_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->right_wrist_real_world_coordinates), &(output->right_wrist_real_world_coordinates)))
  {
    return false;
  }
  // left_hip_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->left_hip_real_world_coordinates), &(output->left_hip_real_world_coordinates)))
  {
    return false;
  }
  // right_hip_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->right_hip_real_world_coordinates), &(output->right_hip_real_world_coordinates)))
  {
    return false;
  }
  // left_knee_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->left_knee_real_world_coordinates), &(output->left_knee_real_world_coordinates)))
  {
    return false;
  }
  // right_knee_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->right_knee_real_world_coordinates), &(output->right_knee_real_world_coordinates)))
  {
    return false;
  }
  // left_ankle_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->left_ankle_real_world_coordinates), &(output->left_ankle_real_world_coordinates)))
  {
    return false;
  }
  // right_ankle_real_world_coordinates
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->right_ankle_real_world_coordinates), &(output->right_ankle_real_world_coordinates)))
  {
    return false;
  }
  return true;
}

object_tracking_messages__msg__PersonDistance *
object_tracking_messages__msg__PersonDistance__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  object_tracking_messages__msg__PersonDistance * msg = (object_tracking_messages__msg__PersonDistance *)allocator.allocate(sizeof(object_tracking_messages__msg__PersonDistance), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(object_tracking_messages__msg__PersonDistance));
  bool success = object_tracking_messages__msg__PersonDistance__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
object_tracking_messages__msg__PersonDistance__destroy(object_tracking_messages__msg__PersonDistance * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    object_tracking_messages__msg__PersonDistance__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
object_tracking_messages__msg__PersonDistance__Sequence__init(object_tracking_messages__msg__PersonDistance__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  object_tracking_messages__msg__PersonDistance * data = NULL;

  if (size) {
    data = (object_tracking_messages__msg__PersonDistance *)allocator.zero_allocate(size, sizeof(object_tracking_messages__msg__PersonDistance), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = object_tracking_messages__msg__PersonDistance__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        object_tracking_messages__msg__PersonDistance__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
object_tracking_messages__msg__PersonDistance__Sequence__fini(object_tracking_messages__msg__PersonDistance__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      object_tracking_messages__msg__PersonDistance__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

object_tracking_messages__msg__PersonDistance__Sequence *
object_tracking_messages__msg__PersonDistance__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  object_tracking_messages__msg__PersonDistance__Sequence * array = (object_tracking_messages__msg__PersonDistance__Sequence *)allocator.allocate(sizeof(object_tracking_messages__msg__PersonDistance__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = object_tracking_messages__msg__PersonDistance__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
object_tracking_messages__msg__PersonDistance__Sequence__destroy(object_tracking_messages__msg__PersonDistance__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    object_tracking_messages__msg__PersonDistance__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
object_tracking_messages__msg__PersonDistance__Sequence__are_equal(const object_tracking_messages__msg__PersonDistance__Sequence * lhs, const object_tracking_messages__msg__PersonDistance__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!object_tracking_messages__msg__PersonDistance__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
object_tracking_messages__msg__PersonDistance__Sequence__copy(
  const object_tracking_messages__msg__PersonDistance__Sequence * input,
  object_tracking_messages__msg__PersonDistance__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(object_tracking_messages__msg__PersonDistance);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    object_tracking_messages__msg__PersonDistance * data =
      (object_tracking_messages__msg__PersonDistance *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!object_tracking_messages__msg__PersonDistance__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          object_tracking_messages__msg__PersonDistance__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!object_tracking_messages__msg__PersonDistance__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
