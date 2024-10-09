from setuptools import find_packages, setup

package_name = 'sensor_presentation'

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
            'sensor_presentation_node = sensor_presentation.sensor_presentation_node:main',  # Adjust this line
        ],
    },
)
