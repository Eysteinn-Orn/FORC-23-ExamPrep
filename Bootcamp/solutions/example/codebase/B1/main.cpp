#include<iostream>

using namespace std;

int add(int a, int b) {
    return a + b;
}

int main(){
    int a, b;
    cout << "Enter an integer: ";
    cin >> a;
    cout << "Enter an integer: ";
    cin >> b;
    cout << "The sum of the integers is " << add(a, b) << endl;
    return 0;
}