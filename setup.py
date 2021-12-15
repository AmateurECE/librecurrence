from setuptools import find_packages, setup
from setuptools.extension import Extension
from Cython.Build import cythonize

librecurrence_pywrapper = Extension(
    name="pyrecurrence",
    sources=["pyrecurrence/recurrence.pyx"],
    libraries=["recurrence"],
    # library_dirs=["build"],
    include_dirs=["recurrence"],
)

setup(
    name="pyrecurrence",
    version="0.1.0",
    packages=find_packages(),
    author="Ethan D. Twardy",
    description="Cython wrapper for librecurrence",
    url="https://github.com/AmateurECE/librecurrence",
    ext_modules=cythonize([librecurrence_pywrapper]),
)
