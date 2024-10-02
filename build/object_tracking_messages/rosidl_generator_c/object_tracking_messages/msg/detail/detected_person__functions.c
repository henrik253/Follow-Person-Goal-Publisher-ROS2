// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from object_tracking_messages:msg/DetectedPerson.idl
// generated code does not contain a copyright notice
#include "object_tracking_messages/msg/detail/detected_person__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `bbox`
#include "object_tracking_messages/msg/detail/bounding_box__functions.h"

bool
object_tracking_messages__msg__DetectedPerson__init(object_tracking_messages__msg__DetectedPerson * msg)
{
  if (!msg) {
    return false;
  }
  // confidence
  // id
  // bbox
  if (!object_tracking_messages__msg__BoundingBox__init(&msg->bbox)) {
    object_tracking_messages__msg__DetectedPerson__fini(msg);
    return false;
  }
  return true;
}

void
object_tracking_messages__msg__DetectedPerson__fini(object_tracking_messages__msg__DetectedPerson * msg)
{
  if (!msg) {
    return;
  }
  // confidence
  // id
  // bbox
  object_tracking_messages__msg__BoundingBox__fini(&msg->bbox);
}

bool
object_tracking_messages__msg__DetectedPerson__are_equal(const object_tracking_messages__msg__DetectedPerson * lhs, const object_tracking_messages__msg__DetectedPerson * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // bbox
  if (!object_tracking_messages__msg__BoundingBox__are_equal(
      &(lhs->bbox), &(rhs->bbox)))
  {
    return false;
  }
  return true;
}

bool
object_tracking_messages__msg__DetectedPerson__copy(
  const object_tracking_messages__msg__DetectedPerson * input,
  object_tracking_messages__msg__DetectedPerson * output)
{
  if (!input || !output) {
    return false;
  }
  // confidence
  output->confidence = input->confidence;
  // id
  output->id = input->id;
  // bbox
  if (!object_tracking_messages__msg__BoundingBox__copy(
      &(input->bbox), &(output->bbox)))
  {
    return false;
  }
  return true;
}

object_tracking_messages__msg__DetectedPerson *
object_tracking_messages__msg__DetectedPerson__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  object_tracking_messages__msg__DetectedPerson * msg = (object_tracking_messages__msg__DetectedPerson *)allocator.allocate(sizeof(object_tracking_messages__msg__DetectedPerson), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(object_tracking_messages__msg__DetectedPerson));
  bool success = object_tracking_messages__msg__DetectedPerson__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
object_tracking_messages__msg__DetectedPerson__destroy(object_tracking_messages__msg__DetectedPerson * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    object_tracking_messages__msg__DetectedPerson__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
object_tracking_messages__msg__DetectedPerson__Sequence__init(object_tracking_messages__msg__DetectedPerson__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  object_tracking_messages__msg__DetectedPerson * data = NULL;

  if (size) {
    data = (object_tracking_messages__msg__DetectedPerson *)allocator.zero_allocate(size, sizeof(object_tracking_messages__msg__DetectedPerson), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = object_tracking_messages__msg__DetectedPerson__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        object_tracking_messages__msg__DetectedPerson__fini(&data[i - 1]);
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
object_tracking_messages__msg__DetectedPerson__Sequence__fini(object_tracking_messages__msg__DetectedPerson__Sequence * array)
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
      object_tracking_messages__msg__DetectedPerson__fini(&array->data[i]);
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

object_tracking_messages__msg__DetectedPerson__Sequence *
object_tracking_messages__msg__DetectedPerson__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  object_tracking_messages__msg__DetectedPerson__Sequence * array = (object_tracking_messages__msg__DetectedPerson__Sequence *)allocator.allocate(sizeof(object_tracking_messages__msg__DetectedPerson__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = object_tracking_messages__msg__DetectedPerson__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
object_tracking_messages__msg__DetectedPerson__Sequence__destroy(object_tracking_messages__msg__DetectedPerson__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    object_tracking_messages__msg__DetectedPerson__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
object_tracking_messages__msg__DetectedPerson__Sequence__are_equal(const object_tracking_messages__msg__DetectedPerson__Sequence * lhs, const object_tracking_messages__msg__DetectedPerson__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!object_tracking_messages__msg__DetectedPerson__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
object_tracking_messages__msg__DetectedPerson__Sequence__copy(
  const object_tracking_messages__msg__DetectedPerson__Sequence * input,
  object_tracking_messages__msg__DetectedPerson__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(object_tracking_messages__msg__DetectedPerson);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    object_tracking_messages__msg__DetectedPerson * data =
      (object_tracking_messages__msg__DetectedPerson *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!object_tracking_messages__msg__DetectedPerson__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          object_tracking_messages__msg__DetectedPerson__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!object_tracking_messages__msg__DetectedPerson__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
