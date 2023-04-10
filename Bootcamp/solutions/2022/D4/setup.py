import pybind11
import setuptools, sysconfig

setuptools.setup(
    name="digit_module",
    ext_modules=[setuptools.Extension(
        "digit_module",
        ["digit_module.cpp"],
        include_dirs=[sysconfig.get_paths()['include'], pybind11.get_include()],
        language="c++"
    )],
)