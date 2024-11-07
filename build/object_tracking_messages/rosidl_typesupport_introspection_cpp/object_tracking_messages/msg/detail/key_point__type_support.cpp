// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from object_tracking_messages:msg/KeyPoint.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "object_tracking_messages/msg/detail/key_point__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace object_tracking_messages
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void KeyPoint_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) object_tracking_messages::msg::KeyPoint(_init);
}

void KeyPoint_fini_function(void * message_memory)
{
  auto typed_message = static_cast<object_tracking_messages::msg::KeyPoint *>(message_memory);
  typed_message->~KeyPoint();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember KeyPoint_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_tracking_messages::msg::KeyPoint, structure_needs_at_least_one_member),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers KeyPoint_message_members = {
  "object_tracking_messages::msg",  // message namespace
  "KeyPoint",  // message name
  1,  // number of fields
  sizeof(object_tracking_messages::msg::KeyPoint),
  KeyPoint_message_member_array,  // message members
  KeyPoint_init_function,  // function to initialize message memory (memory has to be allocated)
  KeyPoint_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t KeyPoint_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &KeyPoint_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace object_tracking_messages


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<object_tracking_messages::msg::KeyPoint>()
{
  return &::object_tracking_messages::msg::rosidl_typesupport_introspection_cpp::KeyPoint_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, object_tracking_messages, msg, KeyPoint)() {
  return &::object_tracking_messages::msg::rosidl_typesupport_introspection_cpp::KeyPoint_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
