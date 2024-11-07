// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from object_tracking_messages:msg/KeyPoint.idl
// generated code does not contain a copyright notice
#include "object_tracking_messages/msg/detail/key_point__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
object_tracking_messages__msg__KeyPoint__init(object_tracking_messages__msg__KeyPoint * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
object_tracking_messages__msg__KeyPoint__fini(object_tracking_messages__msg__KeyPoint * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
object_tracking_messages__msg__KeyPoint__are_equal(const object_tracking_messages__msg__KeyPoint * lhs, const object_tracking_messages__msg__KeyPoint * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
object_tracking_messages__msg__KeyPoint__copy(
  const object_tracking_messages__msg__KeyPoint * input,
  object_tracking_messages__msg__KeyPoint * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

object_tracking_messages__msg__KeyPoint *
object_tracking_messages__msg__KeyPoint__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  object_tracking_messages__msg__KeyPoint * msg = (object_tracking_messages__msg__KeyPoint *)allocator.allocate(sizeof(object_tracking_messages__msg__KeyPoint), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(object_tracking_messages__msg__KeyPoint));
  bool success = object_tracking_messages__msg__KeyPoint__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
object_tracking_messages__msg__KeyPoint__destroy(object_tracking_messages__msg__KeyPoint * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    object_tracking_messages__msg__KeyPoint__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
object_tracking_messages__msg__KeyPoint__Sequence__init(object_tracking_messages__msg__KeyPoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  object_tracking_messages__msg__KeyPoint * data = NULL;

  if (size) {
    data = (object_tracking_messages__msg__KeyPoint *)allocator.zero_allocate(size, sizeof(object_tracking_messages__msg__KeyPoint), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = object_tracking_messages__msg__KeyPoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        object_tracking_messages__msg__KeyPoint__fini(&data[i - 1]);
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
object_tracking_messages__msg__KeyPoint__Sequence__fini(object_tracking_messages__msg__KeyPoint__Sequence * array)
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
      object_tracking_messages__msg__KeyPoint__fini(&array->data[i]);
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

object_tracking_messages__msg__KeyPoint__Sequence *
object_tracking_messages__msg__KeyPoint__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  object_tracking_messages__msg__KeyPoint__Sequence * array = (object_tracking_messages__msg__KeyPoint__Sequence *)allocator.allocate(sizeof(object_tracking_messages__msg__KeyPoint__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = object_tracking_messages__msg__KeyPoint__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
object_tracking_messages__msg__KeyPoint__Sequence__destroy(object_tracking_messages__msg__KeyPoint__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    object_tracking_messages__msg__KeyPoint__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
object_tracking_messages__msg__KeyPoint__Sequence__are_equal(const object_tracking_messages__msg__KeyPoint__Sequence * lhs, const object_tracking_messages__msg__KeyPoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!object_tracking_messages__msg__KeyPoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
object_tracking_messages__msg__KeyPoint__Sequence__copy(
  const object_tracking_messages__msg__KeyPoint__Sequence * input,
  object_tracking_messages__msg__KeyPoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(object_tracking_messages__msg__KeyPoint);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    object_tracking_messages__msg__KeyPoint * data =
      (object_tracking_messages__msg__KeyPoint *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!object_tracking_messages__msg__KeyPoint__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          object_tracking_messages__msg__KeyPoint__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!object_tracking_messages__msg__KeyPoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
