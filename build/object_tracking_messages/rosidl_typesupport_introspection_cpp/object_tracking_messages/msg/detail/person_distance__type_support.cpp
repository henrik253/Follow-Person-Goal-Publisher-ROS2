// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from object_tracking_messages:msg/PersonDistance.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "object_tracking_messages/msg/detail/person_distance__struct.hpp"
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

void PersonDistance_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) object_tracking_messages::msg::PersonDistance(_init);
}

void PersonDistance_fini_function(void * message_memory)
{
  auto typed_message = static_cast<object_tracking_messages::msg::PersonDistance *>(message_memory);
  typed_message->~PersonDistance();
}

size_t size_function__PersonDistance__distances(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PersonDistance__distances(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__PersonDistance__distances(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__PersonDistance__distances(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__PersonDistance__distances(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__PersonDistance__distances(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__PersonDistance__distances(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__PersonDistance__distances(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__PersonDistance__real_world_coordinates(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PersonDistance__real_world_coordinates(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__PersonDistance__real_world_coordinates(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__PersonDistance__real_world_coordinates(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__PersonDistance__real_world_coordinates(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__PersonDistance__real_world_coordinates(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__PersonDistance__real_world_coordinates(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__PersonDistance__real_world_coordinates(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PersonDistance_message_member_array[3] = {
  {
    "detected_persons",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<object_tracking_messages::msg::DetectedPersons>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_tracking_messages::msg::PersonDistance, detected_persons),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "distances",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_tracking_messages::msg::PersonDistance, distances),  // bytes offset in struct
    nullptr,  // default value
    size_function__PersonDistance__distances,  // size() function pointer
    get_const_function__PersonDistance__distances,  // get_const(index) function pointer
    get_function__PersonDistance__distances,  // get(index) function pointer
    fetch_function__PersonDistance__distances,  // fetch(index, &value) function pointer
    assign_function__PersonDistance__distances,  // assign(index, value) function pointer
    resize_function__PersonDistance__distances  // resize(index) function pointer
  },
  {
    "real_world_coordinates",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_tracking_messages::msg::PersonDistance, real_world_coordinates),  // bytes offset in struct
    nullptr,  // default value
    size_function__PersonDistance__real_world_coordinates,  // size() function pointer
    get_const_function__PersonDistance__real_world_coordinates,  // get_const(index) function pointer
    get_function__PersonDistance__real_world_coordinates,  // get(index) function pointer
    fetch_function__PersonDistance__real_world_coordinates,  // fetch(index, &value) function pointer
    assign_function__PersonDistance__real_world_coordinates,  // assign(index, value) function pointer
    resize_function__PersonDistance__real_world_coordinates  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PersonDistance_message_members = {
  "object_tracking_messages::msg",  // message namespace
  "PersonDistance",  // message name
  3,  // number of fields
  sizeof(object_tracking_messages::msg::PersonDistance),
  PersonDistance_message_member_array,  // message members
  PersonDistance_init_function,  // function to initialize message memory (memory has to be allocated)
  PersonDistance_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PersonDistance_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PersonDistance_message_members,
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
get_message_type_support_handle<object_tracking_messages::msg::PersonDistance>()
{
  return &::object_tracking_messages::msg::rosidl_typesupport_introspection_cpp::PersonDistance_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, object_tracking_messages, msg, PersonDistance)() {
  return &::object_tracking_messages::msg::rosidl_typesupport_introspection_cpp::PersonDistance_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
