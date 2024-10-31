from setuptools import find_packages, setup

package_name = 'navigation'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        # Füge hier die Launch-Datei hinzu
        ('share/' + package_name + '/launch', ['launch/nav2_launch.py']),  # Launch-Datei einfügen
        ('share/' + package_name + '/launch', ['launch/navigation_launch.py']),
        ('share/' + package_name + '/launch', ['launch/simulation_launch.py']),
        ('share/' + package_name + '/launch', ['launch/rviz_launch.py']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='student',
    maintainer_email='student@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'goal_publisher_node = navigation.goal_publisher_node:main',
        ],
    },
)
