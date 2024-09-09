from setuptools import find_packages, setup

package_name = 'position_estimation'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='henrik F',
    maintainer_email='hnfl1438@hochschule-trier.de',
    description='A ROS 2 package for position estimation.',
    license='MIT',
    entry_points={
        'console_scripts': [
            'position_estimation_node = position_estimation.position_estimation_node:main'
        ],
    },
)
