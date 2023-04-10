#include <iostream>
#include "adder.h"
using namespace std;

int main(){
    int a, b;
    cout << "Enter an integer: ";
    cin >> a;
    cout << "Enter an integer: ";
    cin >> b;
    Adder adder(a);
    cout << "The sum of the integers is " << adder.add(b) << endl;
    return 0;
}