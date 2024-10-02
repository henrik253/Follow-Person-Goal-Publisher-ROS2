// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from object_tracking_messages:msg/DetectedPersons.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "object_tracking_messages/msg/detail/detected_persons__struct.hpp"
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

void DetectedPersons_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) object_tracking_messages::msg::DetectedPersons(_init);
}

void DetectedPersons_fini_function(void * message_memory)
{
  auto typed_message = static_cast<object_tracking_messages::msg::DetectedPersons *>(message_memory);
  typed_message->~DetectedPersons();
}

size_t size_function__DetectedPersons__persons(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<object_tracking_messages::msg::DetectedPerson> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DetectedPersons__persons(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<object_tracking_messages::msg::DetectedPerson> *>(untyped_member);
  return &member[index];
}

void * get_function__DetectedPersons__persons(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<object_tracking_messages::msg::DetectedPerson> *>(untyped_member);
  return &member[index];
}

void fetch_function__DetectedPersons__persons(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const object_tracking_messages::msg::DetectedPerson *>(
    get_const_function__DetectedPersons__persons(untyped_member, index));
  auto & value = *reinterpret_cast<object_tracking_messages::msg::DetectedPerson *>(untyped_value);
  value = item;
}

void assign_function__DetectedPersons__persons(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<object_tracking_messages::msg::DetectedPerson *>(
    get_function__DetectedPersons__persons(untyped_member, index));
  const auto & value = *reinterpret_cast<const object_tracking_messages::msg::DetectedPerson *>(untyped_value);
  item = value;
}

void resize_function__DetectedPersons__persons(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<object_tracking_messages::msg::DetectedPerson> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DetectedPersons_message_member_array[1] = {
  {
    "persons",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<object_tracking_messages::msg::DetectedPerson>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_tracking_messages::msg::DetectedPersons, persons),  // bytes offset in struct
    nullptr,  // default value
    size_function__DetectedPersons__persons,  // size() function pointer
    get_const_function__DetectedPersons__persons,  // get_const(index) function pointer
    get_function__DetectedPersons__persons,  // get(index) function pointer
    fetch_function__DetectedPersons__persons,  // fetch(index, &value) function pointer
    assign_function__DetectedPersons__persons,  // assign(index, value) function pointer
    resize_function__DetectedPersons__persons  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DetectedPersons_message_members = {
  "object_tracking_messages::msg",  // message namespace
  "DetectedPersons",  // message name
  1,  // number of fields
  sizeof(object_tracking_messages::msg::DetectedPersons),
  DetectedPersons_message_member_array,  // message members
  DetectedPersons_init_function,  // function to initialize message memory (memory has to be allocated)
  DetectedPersons_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DetectedPersons_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DetectedPersons_message_members,
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
get_message_type_support_handle<object_tracking_messages::msg::DetectedPersons>()
{
  return &::object_tracking_messages::msg::rosidl_typesupport_introspection_cpp::DetectedPersons_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, object_tracking_messages, msg, DetectedPersons)() {
  return &::object_tracking_messages::msg::rosidl_typesupport_introspection_cpp::DetectedPersons_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
