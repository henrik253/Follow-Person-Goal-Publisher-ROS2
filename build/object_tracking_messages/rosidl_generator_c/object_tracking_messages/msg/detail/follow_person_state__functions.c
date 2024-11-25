// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from object_tracking_messages:msg/FollowPersonState.idl
// generated code does not contain a copyright notice
#include "object_tracking_messages/msg/detail/follow_person_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `state`
#include "rosidl_runtime_c/string_functions.h"

bool
object_tracking_messages__msg__FollowPersonState__init(object_tracking_messages__msg__FollowPersonState * msg)
{
  if (!msg) {
    return false;
  }
  // state
  if (!rosidl_runtime_c__String__init(&msg->state)) {
    object_tracking_messages__msg__FollowPersonState__fini(msg);
    return false;
  }
  // id
  return true;
}

void
object_tracking_messages__msg__FollowPersonState__fini(object_tracking_messages__msg__FollowPersonState * msg)
{
  if (!msg) {
    return;
  }
  // state
  rosidl_runtime_c__String__fini(&msg->state);
  // id
}

bool
object_tracking_messages__msg__FollowPersonState__are_equal(const object_tracking_messages__msg__FollowPersonState * lhs, const object_tracking_messages__msg__FollowPersonState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // state
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->state), &(rhs->state)))
  {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  return true;
}

bool
object_tracking_messages__msg__FollowPersonState__copy(
  const object_tracking_messages__msg__FollowPersonState * input,
  object_tracking_messages__msg__FollowPersonState * output)
{
  if (!input || !output) {
    return false;
  }
  // state
  if (!rosidl_runtime_c__String__copy(
      &(input->state), &(output->state)))
  {
    return false;
  }
  // id
  output->id = input->id;
  return true;
}

object_tracking_messages__msg__FollowPersonState *
object_tracking_messages__msg__FollowPersonState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  object_tracking_messages__msg__FollowPersonState * msg = (object_tracking_messages__msg__FollowPersonState *)allocator.allocate(sizeof(object_tracking_messages__msg__FollowPersonState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(object_tracking_messages__msg__FollowPersonState));
  bool success = object_tracking_messages__msg__FollowPersonState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
object_tracking_messages__msg__FollowPersonState__destroy(object_tracking_messages__msg__FollowPersonState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    object_tracking_messages__msg__FollowPersonState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
object_tracking_messages__msg__FollowPersonState__Sequence__init(object_tracking_messages__msg__FollowPersonState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  object_tracking_messages__msg__FollowPersonState * data = NULL;

  if (size) {
    data = (object_tracking_messages__msg__FollowPersonState *)allocator.zero_allocate(size, sizeof(object_tracking_messages__msg__FollowPersonState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = object_tracking_messages__msg__FollowPersonState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        object_tracking_messages__msg__FollowPersonState__fini(&data[i - 1]);
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
object_tracking_messages__msg__FollowPersonState__Sequence__fini(object_tracking_messages__msg__FollowPersonState__Sequence * array)
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
      object_tracking_messages__msg__FollowPersonState__fini(&array->data[i]);
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

object_tracking_messages__msg__FollowPersonState__Sequence *
object_tracking_messages__msg__FollowPersonState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  object_tracking_messages__msg__FollowPersonState__Sequence * array = (object_tracking_messages__msg__FollowPersonState__Sequence *)allocator.allocate(sizeof(object_tracking_messages__msg__FollowPersonState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = object_tracking_messages__msg__FollowPersonState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
object_tracking_messages__msg__FollowPersonState__Sequence__destroy(object_tracking_messages__msg__FollowPersonState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    object_tracking_messages__msg__FollowPersonState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
object_tracking_messages__msg__FollowPersonState__Sequence__are_equal(const object_tracking_messages__msg__FollowPersonState__Sequence * lhs, const object_tracking_messages__msg__FollowPersonState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!object_tracking_messages__msg__FollowPersonState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
object_tracking_messages__msg__FollowPersonState__Sequence__copy(
  const object_tracking_messages__msg__FollowPersonState__Sequence * input,
  object_tracking_messages__msg__FollowPersonState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(object_tracking_messages__msg__FollowPersonState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    object_tracking_messages__msg__FollowPersonState * data =
      (object_tracking_messages__msg__FollowPersonState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!object_tracking_messages__msg__FollowPersonState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          object_tracking_messages__msg__FollowPersonState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!object_tracking_messages__msg__FollowPersonState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
