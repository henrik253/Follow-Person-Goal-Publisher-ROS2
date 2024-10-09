# generated from rosidl_generator_py/resource/_idl.py.em
# with input from object_tracking_messages:msg/DetectedPerson.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DetectedPerson(type):
    """Metaclass of message 'DetectedPerson'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('object_tracking_messages')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'object_tracking_messages.msg.DetectedPerson')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__detected_person
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__detected_person
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__detected_person
            cls._TYPE_SUPPORT = module.type_support_msg__msg__detected_person
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__detected_person

            from object_tracking_messages.msg import BoundingBox
            if BoundingBox.__class__._TYPE_SUPPORT is None:
                BoundingBox.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DetectedPerson(metaclass=Metaclass_DetectedPerson):
    """Message class 'DetectedPerson'."""

    __slots__ = [
        '_confidence',
        '_id',
        '_bbox',
    ]

    _fields_and_field_types = {
        'confidence': 'float',
        'id': 'int32',
        'bbox': 'object_tracking_messages/BoundingBox',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['object_tracking_messages', 'msg'], 'BoundingBox'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.confidence = kwargs.get('confidence', float())
        self.id = kwargs.get('id', int())
        from object_tracking_messages.msg import BoundingBox
        self.bbox = kwargs.get('bbox', BoundingBox())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.confidence != other.confidence:
            return False
        if self.id != other.id:
            return False
        if self.bbox != other.bbox:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def confidence(self):
        """Message field 'confidence'."""
        return self._confidence

    @confidence.setter
    def confidence(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'confidence' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'confidence' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._confidence = value

    @builtins.property  # noqa: A003
    def id(self):  # noqa: A003
        """Message field 'id'."""
        return self._id

    @id.setter  # noqa: A003
    def id(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'id' field must be an integer in [-2147483648, 2147483647]"
        self._id = value

    @builtins.property
    def bbox(self):
        """Message field 'bbox'."""
        return self._bbox

    @bbox.setter
    def bbox(self, value):
        if __debug__:
            from object_tracking_messages.msg import BoundingBox
            assert \
                isinstance(value, BoundingBox), \
                "The 'bbox' field must be a sub message of type 'BoundingBox'"
        self._bbox = value