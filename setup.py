from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize

librecurrence_pywrapper = Extension(
    name="pyrecurrence",
    sources=["pyrecurrence/recurrence.pyx"],
    libraries=["recurrence"],
    library_dirs=["build"],
    include_dirs=["recurrence"],
)
setup(
    name="pyrecurrence",
    ext_modules=cythonize([librecurrence_pywrapper]),
)
