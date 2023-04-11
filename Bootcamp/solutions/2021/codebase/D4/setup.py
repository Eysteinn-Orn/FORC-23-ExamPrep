import pybind11
import setuptools, sysconfig

# put your module name here
module_name = "digit_count_module"

# put the names of the source files here
module_files = [
    "digit_count_module.cpp"
]


setuptools.setup(
    name=module_name,
    ext_modules=[setuptools.Extension(
        module_name,
        module_files,
        include_dirs=[sysconfig.get_paths()['include'], pybind11.get_include()],
        language="c++"
    )],
)