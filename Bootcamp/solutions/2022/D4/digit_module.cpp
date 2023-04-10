#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>

using namespace std;

int most_significant_digit(int n) {
    while(n >= 10) {
        n /= 10;
    }
    return n;
}

vector<int> most_significant_digits(vector<int> nums) {
    vector<int> result;

    for(int n: nums) {
        result.push_back(
            most_significant_digit(n)
        );
    }

    return result;
}

PYBIND11_MODULE(digit_module, m) {
    m.def("get_most_significant_digit_for_integers", &most_significant_digits, "Get most significant digits");
}