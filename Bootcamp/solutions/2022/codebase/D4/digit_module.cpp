#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <iostream>
#include <vector>

int most_significant_digit(int n) {
    while(n >= 10) {
        n/= 10;
    }
    return n;
}

std::vector<int> get_most_significant_digit_for_integers(std::vector<int> numbers) {
    std::vector<int> digits;
    for(auto &n: numbers) {
        digits.push_back(most_significant_digit(n));
    }

    return digits;
}


PYBIND11_MODULE(digit_module, m) {

    // add functions like this
    m.def(

        // what the function should be called in the python module
        "get_most_significant_digit_for_integers", 

        // pointer to your c++ function
        &get_most_significant_digit_for_integers, 

        // description of the function
        "Get most significant digits"
    );
}
