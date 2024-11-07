// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from object_tracking_messages:msg/PersonKeyPoint.idl
// generated code does not contain a copyright notice
#include "object_tracking_messages/msg/detail/person_key_point__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
object_tracking_messages__msg__PersonKeyPoint__init(object_tracking_messages__msg__PersonKeyPoint * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // confidence
  return true;
}

void
object_tracking_messages__msg__PersonKeyPoint__fini(object_tracking_messages__msg__PersonKeyPoint * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // confidence
}

bool
object_tracking_messages__msg__PersonKeyPoint__are_equal(const object_tracking_messages__msg__PersonKeyPoint * lhs, const object_tracking_messages__msg__PersonKeyPoint * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  return true;
}

bool
object_tracking_messages__msg__PersonKeyPoint__copy(
  const object_tracking_messages__msg__PersonKeyPoint * input,
  object_tracking_messages__msg__PersonKeyPoint * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // confidence
  output->confidence = input->confidence;
  return true;
}

object_tracking_messages__msg__PersonKeyPoint *
object_tracking_messages__msg__PersonKeyPoint__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  object_tracking_messages__msg__PersonKeyPoint * msg = (object_tracking_messages__msg__PersonKeyPoint *)allocator.allocate(sizeof(object_tracking_messages__msg__PersonKeyPoint), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(object_tracking_messages__msg__PersonKeyPoint));
  bool success = object_tracking_messages__msg__PersonKeyPoint__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
object_tracking_messages__msg__PersonKeyPoint__destroy(object_tracking_messages__msg__PersonKeyPoint * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    object_tracking_messages__msg__PersonKeyPoint__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
object_tracking_messages__msg__PersonKeyPoint__Sequence__init(object_tracking_messages__msg__PersonKeyPoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  object_tracking_messages__msg__PersonKeyPoint * data = NULL;

  if (size) {
    data = (object_tracking_messages__msg__PersonKeyPoint *)allocator.zero_allocate(size, sizeof(object_tracking_messages__msg__PersonKeyPoint), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = object_tracking_messages__msg__PersonKeyPoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        object_tracking_messages__msg__PersonKeyPoint__fini(&data[i - 1]);
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
object_tracking_messages__msg__PersonKeyPoint__Sequence__fini(object_tracking_messages__msg__PersonKeyPoint__Sequence * array)
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
      object_tracking_messages__msg__PersonKeyPoint__fini(&array->data[i]);
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

object_tracking_messages__msg__PersonKeyPoint__Sequence *
object_tracking_messages__msg__PersonKeyPoint__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  object_tracking_messages__msg__PersonKeyPoint__Sequence * array = (object_tracking_messages__msg__PersonKeyPoint__Sequence *)allocator.allocate(sizeof(object_tracking_messages__msg__PersonKeyPoint__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = object_tracking_messages__msg__PersonKeyPoint__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
object_tracking_messages__msg__PersonKeyPoint__Sequence__destroy(object_tracking_messages__msg__PersonKeyPoint__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    object_tracking_messages__msg__PersonKeyPoint__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
object_tracking_messages__msg__PersonKeyPoint__Sequence__are_equal(const object_tracking_messages__msg__PersonKeyPoint__Sequence * lhs, const object_tracking_messages__msg__PersonKeyPoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!object_tracking_messages__msg__PersonKeyPoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
object_tracking_messages__msg__PersonKeyPoint__Sequence__copy(
  const object_tracking_messages__msg__PersonKeyPoint__Sequence * input,
  object_tracking_messages__msg__PersonKeyPoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(object_tracking_messages__msg__PersonKeyPoint);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    object_tracking_messages__msg__PersonKeyPoint * data =
      (object_tracking_messages__msg__PersonKeyPoint *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!object_tracking_messages__msg__PersonKeyPoint__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          object_tracking_messages__msg__PersonKeyPoint__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!object_tracking_messages__msg__PersonKeyPoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
