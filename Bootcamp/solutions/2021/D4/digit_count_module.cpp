#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>

using namespace std;

vector<int> digit_count(vector<int> lis) {
    vector<int> result;

    for(int n: lis) {
        int dig_count = 0;
        while(n != 0) {
            n /= 10;
            dig_count++;
        }
        result.push_back(dig_count);
    }

    return result;
}

PYBIND11_MODULE(digit_count_module, m) {
    // m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("get_digit_count_for_integers", &digit_count, "Get digit count");
}

