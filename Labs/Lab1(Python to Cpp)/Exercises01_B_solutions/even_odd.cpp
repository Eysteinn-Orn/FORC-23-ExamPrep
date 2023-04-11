#include <iostream>

using namespace std;

bool is_even(int n){
    if(n & 0x01){
        return false;
    }
    return true;
}

bool is_odd(int n){
    if(n & 0x01){
        return true;
    }
    return false;
}

int main(){
    int i;

    while(i != 0){
        cout << "What's the number? ";
        cin >> i;
        cout << i << " is odd?  " << is_odd(i) << endl;
        cout << i << " is even? " << is_even(i) << endl;
    }


    return 0;
}