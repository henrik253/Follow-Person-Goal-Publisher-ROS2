// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from object_tracking_messages:msg/DetectedPerson.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "object_tracking_messages/msg/detail/detected_person__struct.hpp"
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

void DetectedPerson_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) object_tracking_messages::msg::DetectedPerson(_init);
}

void DetectedPerson_fini_function(void * message_memory)
{
  auto typed_message = static_cast<object_tracking_messages::msg::DetectedPerson *>(message_memory);
  typed_message->~DetectedPerson();
}

size_t size_function__DetectedPerson__body_parts(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DetectedPerson__body_parts(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__DetectedPerson__body_parts(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__DetectedPerson__body_parts(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__DetectedPerson__body_parts(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__DetectedPerson__body_parts(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__DetectedPerson__body_parts(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__DetectedPerson__body_parts(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__DetectedPerson__person_key_point(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<object_tracking_messages::msg::PersonKeyPoint> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DetectedPerson__person_key_point(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<object_tracking_messages::msg::PersonKeyPoint> *>(untyped_member);
  return &member[index];
}

void * get_function__DetectedPerson__person_key_point(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<object_tracking_messages::msg::PersonKeyPoint> *>(untyped_member);
  return &member[index];
}

void fetch_function__DetectedPerson__person_key_point(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const object_tracking_messages::msg::PersonKeyPoint *>(
    get_const_function__DetectedPerson__person_key_point(untyped_member, index));
  auto & value = *reinterpret_cast<object_tracking_messages::msg::PersonKeyPoint *>(untyped_value);
  value = item;
}

void assign_function__DetectedPerson__person_key_point(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<object_tracking_messages::msg::PersonKeyPoint *>(
    get_function__DetectedPerson__person_key_point(untyped_member, index));
  const auto & value = *reinterpret_cast<const object_tracking_messages::msg::PersonKeyPoint *>(untyped_value);
  item = value;
}

void resize_function__DetectedPerson__person_key_point(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<object_tracking_messages::msg::PersonKeyPoint> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DetectedPerson_message_member_array[6] = {
  {
    "label",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_tracking_messages::msg::DetectedPerson, label),  // bytes offset in struct
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
    offsetof(object_tracking_messages::msg::DetectedPerson, confidence),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_tracking_messages::msg::DetectedPerson, id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "bbox",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<object_tracking_messages::msg::BoundingBox>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_tracking_messages::msg::DetectedPerson, bbox),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "body_parts",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_tracking_messages::msg::DetectedPerson, body_parts),  // bytes offset in struct
    nullptr,  // default value
    size_function__DetectedPerson__body_parts,  // size() function pointer
    get_const_function__DetectedPerson__body_parts,  // get_const(index) function pointer
    get_function__DetectedPerson__body_parts,  // get(index) function pointer
    fetch_function__DetectedPerson__body_parts,  // fetch(index, &value) function pointer
    assign_function__DetectedPerson__body_parts,  // assign(index, value) function pointer
    resize_function__DetectedPerson__body_parts  // resize(index) function pointer
  },
  {
    "person_key_point",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<object_tracking_messages::msg::PersonKeyPoint>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_tracking_messages::msg::DetectedPerson, person_key_point),  // bytes offset in struct
    nullptr,  // default value
    size_function__DetectedPerson__person_key_point,  // size() function pointer
    get_const_function__DetectedPerson__person_key_point,  // get_const(index) function pointer
    get_function__DetectedPerson__person_key_point,  // get(index) function pointer
    fetch_function__DetectedPerson__person_key_point,  // fetch(index, &value) function pointer
    assign_function__DetectedPerson__person_key_point,  // assign(index, value) function pointer
    resize_function__DetectedPerson__person_key_point  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DetectedPerson_message_members = {
  "object_tracking_messages::msg",  // message namespace
  "DetectedPerson",  // message name
  6,  // number of fields
  sizeof(object_tracking_messages::msg::DetectedPerson),
  DetectedPerson_message_member_array,  // message members
  DetectedPerson_init_function,  // function to initialize message memory (memory has to be allocated)
  DetectedPerson_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DetectedPerson_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DetectedPerson_message_members,
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
get_message_type_support_handle<object_tracking_messages::msg::DetectedPerson>()
{
  return &::object_tracking_messages::msg::rosidl_typesupport_introspection_cpp::DetectedPerson_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, object_tracking_messages, msg, DetectedPerson)() {
  return &::object_tracking_messages::msg::rosidl_typesupport_introspection_cpp::DetectedPerson_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
