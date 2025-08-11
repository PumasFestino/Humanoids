from setuptools import find_packages
from setuptools import setup

setup(
    name='hdwr_pkg',
    version='0.0.0',
    packages=find_packages(
        include=('hdwr_pkg', 'hdwr_pkg.*')),
)
