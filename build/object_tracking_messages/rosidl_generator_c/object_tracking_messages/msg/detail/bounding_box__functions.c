// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from object_tracking_messages:msg/BoundingBox.idl
// generated code does not contain a copyright notice
#include "object_tracking_messages/msg/detail/bounding_box__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
object_tracking_messages__msg__BoundingBox__init(object_tracking_messages__msg__BoundingBox * msg)
{
  if (!msg) {
    return false;
  }
  // x_min
  // y_min
  // x_max
  // y_max
  return true;
}

void
object_tracking_messages__msg__BoundingBox__fini(object_tracking_messages__msg__BoundingBox * msg)
{
  if (!msg) {
    return;
  }
  // x_min
  // y_min
  // x_max
  // y_max
}

bool
object_tracking_messages__msg__BoundingBox__are_equal(const object_tracking_messages__msg__BoundingBox * lhs, const object_tracking_messages__msg__BoundingBox * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x_min
  if (lhs->x_min != rhs->x_min) {
    return false;
  }
  // y_min
  if (lhs->y_min != rhs->y_min) {
    return false;
  }
  // x_max
  if (lhs->x_max != rhs->x_max) {
    return false;
  }
  // y_max
  if (lhs->y_max != rhs->y_max) {
    return false;
  }
  return true;
}

bool
object_tracking_messages__msg__BoundingBox__copy(
  const object_tracking_messages__msg__BoundingBox * input,
  object_tracking_messages__msg__BoundingBox * output)
{
  if (!input || !output) {
    return false;
  }
  // x_min
  output->x_min = input->x_min;
  // y_min
  output->y_min = input->y_min;
  // x_max
  output->x_max = input->x_max;
  // y_max
  output->y_max = input->y_max;
  return true;
}

object_tracking_messages__msg__BoundingBox *
object_tracking_messages__msg__BoundingBox__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  object_tracking_messages__msg__BoundingBox * msg = (object_tracking_messages__msg__BoundingBox *)allocator.allocate(sizeof(object_tracking_messages__msg__BoundingBox), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(object_tracking_messages__msg__BoundingBox));
  bool success = object_tracking_messages__msg__BoundingBox__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
object_tracking_messages__msg__BoundingBox__destroy(object_tracking_messages__msg__BoundingBox * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    object_tracking_messages__msg__BoundingBox__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
object_tracking_messages__msg__BoundingBox__Sequence__init(object_tracking_messages__msg__BoundingBox__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  object_tracking_messages__msg__BoundingBox * data = NULL;

  if (size) {
    data = (object_tracking_messages__msg__BoundingBox *)allocator.zero_allocate(size, sizeof(object_tracking_messages__msg__BoundingBox), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = object_tracking_messages__msg__BoundingBox__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        object_tracking_messages__msg__BoundingBox__fini(&data[i - 1]);
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
object_tracking_messages__msg__BoundingBox__Sequence__fini(object_tracking_messages__msg__BoundingBox__Sequence * array)
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
      object_tracking_messages__msg__BoundingBox__fini(&array->data[i]);
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

object_tracking_messages__msg__BoundingBox__Sequence *
object_tracking_messages__msg__BoundingBox__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  object_tracking_messages__msg__BoundingBox__Sequence * array = (object_tracking_messages__msg__BoundingBox__Sequence *)allocator.allocate(sizeof(object_tracking_messages__msg__BoundingBox__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = object_tracking_messages__msg__BoundingBox__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
object_tracking_messages__msg__BoundingBox__Sequence__destroy(object_tracking_messages__msg__BoundingBox__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    object_tracking_messages__msg__BoundingBox__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
object_tracking_messages__msg__BoundingBox__Sequence__are_equal(const object_tracking_messages__msg__BoundingBox__Sequence * lhs, const object_tracking_messages__msg__BoundingBox__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!object_tracking_messages__msg__BoundingBox__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
object_tracking_messages__msg__BoundingBox__Sequence__copy(
  const object_tracking_messages__msg__BoundingBox__Sequence * input,
  object_tracking_messages__msg__BoundingBox__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(object_tracking_messages__msg__BoundingBox);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    object_tracking_messages__msg__BoundingBox * data =
      (object_tracking_messages__msg__BoundingBox *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!object_tracking_messages__msg__BoundingBox__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          object_tracking_messages__msg__BoundingBox__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!object_tracking_messages__msg__BoundingBox__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
