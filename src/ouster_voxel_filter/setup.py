from setuptools import find_packages, setup

package_name = 'ouster_voxel_filter'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='student',
    maintainer_email='hnfl1438@fh-trier.de',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'voxel_filter_node = ouster_voxel_filter.voxel_filter_node:main',
            'odom_publisher = ouster_voxel_filter.odom_publisher:main',
        ],
    },
)
