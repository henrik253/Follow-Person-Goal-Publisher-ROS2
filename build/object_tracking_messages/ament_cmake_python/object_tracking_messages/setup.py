from setuptools import find_packages
from setuptools import setup

setup(
    name='object_tracking_messages',
    version='0.0.0',
    packages=find_packages(
        include=('object_tracking_messages', 'object_tracking_messages.*')),
)
