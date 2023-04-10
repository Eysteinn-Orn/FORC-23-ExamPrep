# Easy Python modules for C++

Instead of using the method showed in the course, using pybind11 is much, much easier to make python modules for c++.

In the exam, you can use this as a template. 

# Installing
In the problem directory, make a python virtual environment: 
```bash
python3 -m venv .venv
```

Activate it:
```bash
source .venv/bin/activate
```

Install pybind11:
```bash
pip install pybind11
```


# Making the module
Say we are making the `digit_module` in D4 in the 2022 exam. We write our c++ code to solve the problem:

`digit_module.cpp`:
```c++
#include <vector>

using namespace std;

vector<int> most_significant_digits(vector<int> nums) {
    ...
}

```

Now we add the pybind11 code. We add the headers, and the pybind11 code.

```c++
// pybind11 headers
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <vector>

using namespace std;

vector<int> most_significant_digits(vector<int> nums) {
    // function implementation
}

PYBIND11_MODULE(digit_module, m) {
    m.def(
        // what the function should be called in the python module
        "get_most_significant_digit_for_integers", 
        // pointer to your c++ function
        &most_significant_digits, 
        // description of the function
        "Get most significant digits"
    );
}
```

To use it for your use case, replace the appropriate parameters to `m.def`. It is easy to add more functions, just call `m.def` again:


```c++
// pybind11 headers
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <vector>

using namespace std;

vector<int> most_significant_digits(vector<int> nums) {
    // function implementation
}

vector<int> least_significant_digits(vector<int> nums) {
    // function implementation
}


PYBIND11_MODULE(digit_module, m) {
    m.def(
        "get_most_significant_digit_for_integers", 
        &most_significant_digits, 
        "Get most significant digits"
    );
    m.def(
        "get_least_significant_digit_for_integers", 
        &least_significant_digits, 
        "Get least significant digits"
    );
}
```

Then, in the `setup.py` file, add the following code:

```python
import pybind11
import setuptools, sysconfig

# put your module name here
module_name = "digit_module"

# put the names of the source files here
module_files = [
    "digit_module.cpp"
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
```
and replace `module_name` and `module_files` appropriately.

And you're done! To install the module into the python environment, call 
```bash
pip install -e .
```
in the directory where the `setup.py` is located.

# Python List -> std::vector -> Python List
PyBind11 will automatically convert the passed data structure (such as a list) to the appropriate std data structure. For example, it automatically converts a python list to a std::vector, and back.
