// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from object_tracking_messages:msg/KeyPoint.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__KEY_POINT__FUNCTIONS_H_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__KEY_POINT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "object_tracking_messages/msg/rosidl_generator_c__visibility_control.h"

#include "object_tracking_messages/msg/detail/key_point__struct.h"

/// Initialize msg/KeyPoint message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * object_tracking_messages__msg__KeyPoint
 * )) before or use
 * object_tracking_messages__msg__KeyPoint__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_object_tracking_messages
bool
object_tracking_messages__msg__KeyPoint__init(object_tracking_messages__msg__KeyPoint * msg);

/// Finalize msg/KeyPoint message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_object_tracking_messages
void
object_tracking_messages__msg__KeyPoint__fini(object_tracking_messages__msg__KeyPoint * msg);

/// Create msg/KeyPoint message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * object_tracking_messages__msg__KeyPoint__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_object_tracking_messages
object_tracking_messages__msg__KeyPoint *
object_tracking_messages__msg__KeyPoint__create();

/// Destroy msg/KeyPoint message.
/**
 * It calls
 * object_tracking_messages__msg__KeyPoint__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_object_tracking_messages
void
object_tracking_messages__msg__KeyPoint__destroy(object_tracking_messages__msg__KeyPoint * msg);

/// Check for msg/KeyPoint message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_object_tracking_messages
bool
object_tracking_messages__msg__KeyPoint__are_equal(const object_tracking_messages__msg__KeyPoint * lhs, const object_tracking_messages__msg__KeyPoint * rhs);

/// Copy a msg/KeyPoint message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_object_tracking_messages
bool
object_tracking_messages__msg__KeyPoint__copy(
  const object_tracking_messages__msg__KeyPoint * input,
  object_tracking_messages__msg__KeyPoint * output);

/// Initialize array of msg/KeyPoint messages.
/**
 * It allocates the memory for the number of elements and calls
 * object_tracking_messages__msg__KeyPoint__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_object_tracking_messages
bool
object_tracking_messages__msg__KeyPoint__Sequence__init(object_tracking_messages__msg__KeyPoint__Sequence * array, size_t size);

/// Finalize array of msg/KeyPoint messages.
/**
 * It calls
 * object_tracking_messages__msg__KeyPoint__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_object_tracking_messages
void
object_tracking_messages__msg__KeyPoint__Sequence__fini(object_tracking_messages__msg__KeyPoint__Sequence * array);

/// Create array of msg/KeyPoint messages.
/**
 * It allocates the memory for the array and calls
 * object_tracking_messages__msg__KeyPoint__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_object_tracking_messages
object_tracking_messages__msg__KeyPoint__Sequence *
object_tracking_messages__msg__KeyPoint__Sequence__create(size_t size);

/// Destroy array of msg/KeyPoint messages.
/**
 * It calls
 * object_tracking_messages__msg__KeyPoint__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_object_tracking_messages
void
object_tracking_messages__msg__KeyPoint__Sequence__destroy(object_tracking_messages__msg__KeyPoint__Sequence * array);

/// Check for msg/KeyPoint message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_object_tracking_messages
bool
object_tracking_messages__msg__KeyPoint__Sequence__are_equal(const object_tracking_messages__msg__KeyPoint__Sequence * lhs, const object_tracking_messages__msg__KeyPoint__Sequence * rhs);

/// Copy an array of msg/KeyPoint messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_object_tracking_messages
bool
object_tracking_messages__msg__KeyPoint__Sequence__copy(
  const object_tracking_messages__msg__KeyPoint__Sequence * input,
  object_tracking_messages__msg__KeyPoint__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__KEY_POINT__FUNCTIONS_H_
