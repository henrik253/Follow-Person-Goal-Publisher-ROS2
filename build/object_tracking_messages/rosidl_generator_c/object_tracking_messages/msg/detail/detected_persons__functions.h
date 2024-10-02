// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from object_tracking_messages:msg/DetectedPersons.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSONS__FUNCTIONS_H_
#define OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSONS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "object_tracking_messages/msg/rosidl_generator_c__visibility_control.h"

#include "object_tracking_messages/msg/detail/detected_persons__struct.h"

/// Initialize msg/DetectedPersons message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * object_tracking_messages__msg__DetectedPersons
 * )) before or use
 * object_tracking_messages__msg__DetectedPersons__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_object_tracking_messages
bool
object_tracking_messages__msg__DetectedPersons__init(object_tracking_messages__msg__DetectedPersons * msg);

/// Finalize msg/DetectedPersons message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_object_tracking_messages
void
object_tracking_messages__msg__DetectedPersons__fini(object_tracking_messages__msg__DetectedPersons * msg);

/// Create msg/DetectedPersons message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * object_tracking_messages__msg__DetectedPersons__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_object_tracking_messages
object_tracking_messages__msg__DetectedPersons *
object_tracking_messages__msg__DetectedPersons__create();

/// Destroy msg/DetectedPersons message.
/**
 * It calls
 * object_tracking_messages__msg__DetectedPersons__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_object_tracking_messages
void
object_tracking_messages__msg__DetectedPersons__destroy(object_tracking_messages__msg__DetectedPersons * msg);

/// Check for msg/DetectedPersons message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_object_tracking_messages
bool
object_tracking_messages__msg__DetectedPersons__are_equal(const object_tracking_messages__msg__DetectedPersons * lhs, const object_tracking_messages__msg__DetectedPersons * rhs);

/// Copy a msg/DetectedPersons message.
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
object_tracking_messages__msg__DetectedPersons__copy(
  const object_tracking_messages__msg__DetectedPersons * input,
  object_tracking_messages__msg__DetectedPersons * output);

/// Initialize array of msg/DetectedPersons messages.
/**
 * It allocates the memory for the number of elements and calls
 * object_tracking_messages__msg__DetectedPersons__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_object_tracking_messages
bool
object_tracking_messages__msg__DetectedPersons__Sequence__init(object_tracking_messages__msg__DetectedPersons__Sequence * array, size_t size);

/// Finalize array of msg/DetectedPersons messages.
/**
 * It calls
 * object_tracking_messages__msg__DetectedPersons__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_object_tracking_messages
void
object_tracking_messages__msg__DetectedPersons__Sequence__fini(object_tracking_messages__msg__DetectedPersons__Sequence * array);

/// Create array of msg/DetectedPersons messages.
/**
 * It allocates the memory for the array and calls
 * object_tracking_messages__msg__DetectedPersons__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_object_tracking_messages
object_tracking_messages__msg__DetectedPersons__Sequence *
object_tracking_messages__msg__DetectedPersons__Sequence__create(size_t size);

/// Destroy array of msg/DetectedPersons messages.
/**
 * It calls
 * object_tracking_messages__msg__DetectedPersons__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_object_tracking_messages
void
object_tracking_messages__msg__DetectedPersons__Sequence__destroy(object_tracking_messages__msg__DetectedPersons__Sequence * array);

/// Check for msg/DetectedPersons message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_object_tracking_messages
bool
object_tracking_messages__msg__DetectedPersons__Sequence__are_equal(const object_tracking_messages__msg__DetectedPersons__Sequence * lhs, const object_tracking_messages__msg__DetectedPersons__Sequence * rhs);

/// Copy an array of msg/DetectedPersons messages.
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
object_tracking_messages__msg__DetectedPersons__Sequence__copy(
  const object_tracking_messages__msg__DetectedPersons__Sequence * input,
  object_tracking_messages__msg__DetectedPersons__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // OBJECT_TRACKING_MESSAGES__MSG__DETAIL__DETECTED_PERSONS__FUNCTIONS_H_
