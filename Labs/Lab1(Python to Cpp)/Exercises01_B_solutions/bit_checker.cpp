#include <iostream>

using namespace std;

bool is_bit_set(unsigned char byte, int place){
    unsigned char checker = 1;
    for(int i = 1; i < place; ++i){
        checker = checker << 1;
    }
    /*
        check order of operations:
        if((byte & checker) == 0)
        vs.
        if(byte & checker == 0)
        TRY BOTH!!
    */
    if((byte & checker) == 0){
        return false;
    }
    else{
        return true;
    }
}

int main(){
    unsigned char c = 185;
    cout << is_bit_set(c, 1) << endl;
    cout << is_bit_set(c, 2) << endl;
    cout << is_bit_set(c, 3) << endl;
    cout << is_bit_set(c, 4) << endl;
    cout << is_bit_set(c, 5) << endl;
    cout << is_bit_set(c, 6) << endl;
    cout << is_bit_set(c, 7) << endl;
    cout << is_bit_set(c, 8) << endl;

    return 0;
}