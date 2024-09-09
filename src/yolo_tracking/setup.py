from setuptools import setup

package_name = 'yolo_tracking'

setup(
    name=package_name,
    version='0.0.0',
    packages=['yolo_tracking'],  # This should match the directory name of your package
    py_modules=[
        'yolo_tracking.object_detection_node',  # Update to match your Python script name
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='your_name',
    maintainer_email='your_email@example.com',
    description='YOLOv8-based human tracking ROS2 node',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'object_detection_node = yolo_tracking.object_detection_node:main',  # Entry point for your script
        ],
    },
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
)
