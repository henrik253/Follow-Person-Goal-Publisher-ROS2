// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from object_tracking_messages:msg/PersonKeyPoint.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "object_tracking_messages/msg/detail/person_key_point__struct.hpp"
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

void PersonKeyPoint_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) object_tracking_messages::msg::PersonKeyPoint(_init);
}

void PersonKeyPoint_fini_function(void * message_memory)
{
  auto typed_message = static_cast<object_tracking_messages::msg::PersonKeyPoint *>(message_memory);
  typed_message->~PersonKeyPoint();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PersonKeyPoint_message_member_array[3] = {
  {
    "x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_tracking_messages::msg::PersonKeyPoint, x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_tracking_messages::msg::PersonKeyPoint, y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "confidence",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_tracking_messages::msg::PersonKeyPoint, confidence),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PersonKeyPoint_message_members = {
  "object_tracking_messages::msg",  // message namespace
  "PersonKeyPoint",  // message name
  3,  // number of fields
  sizeof(object_tracking_messages::msg::PersonKeyPoint),
  PersonKeyPoint_message_member_array,  // message members
  PersonKeyPoint_init_function,  // function to initialize message memory (memory has to be allocated)
  PersonKeyPoint_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PersonKeyPoint_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PersonKeyPoint_message_members,
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
get_message_type_support_handle<object_tracking_messages::msg::PersonKeyPoint>()
{
  return &::object_tracking_messages::msg::rosidl_typesupport_introspection_cpp::PersonKeyPoint_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, object_tracking_messages, msg, PersonKeyPoint)() {
  return &::object_tracking_messages::msg::rosidl_typesupport_introspection_cpp::PersonKeyPoint_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
