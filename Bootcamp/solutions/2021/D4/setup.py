import pybind11
import setuptools, sysconfig

setuptools.setup(
    name="digit_count_module",
    ext_modules=[setuptools.Extension(
        "digit_count_module",
        ["digit_count_module.cpp"],
        include_dirs=[sysconfig.get_paths()['include'], pybind11.get_include()],
        language="c++"
    )],
)

