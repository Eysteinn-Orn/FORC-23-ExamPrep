#include <iostream>

#include "result.h"
using namespace std;

int main(){
    Result p1;
    cout << p1 << endl;
    Result p2("einar", 7, 12.3, false);
    cout << p2 << endl;
    p1.set_analyst("dr. Kari");
    p1.set_count(23);
    p1.set_amount(8.7);
    p1.set_confirmed(true);
    cout << p1 << endl;
    Result p3(p2);
    cout << p3 << endl;
    p2.set_analyst("dr. Einar");
    p3.set_analyst("dr. Skuli");
    p3.set_count(57);
    p3.set_amount(11.0);
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    p3.set_confirmed(true);
    cout << "p2.analyst: " << p2.get_analyst() << endl;
    cout << "p3.count: " << p3.get_count() << endl;
    if(p1.get_confirmed()){
        cout << "p1 confirmed" << endl;
    }
    if(p2.get_confirmed()){
        cout << "p2 confirmed" << endl;
    }
    if(p3.get_confirmed()){
        cout << "p3 confirmed" << endl;
    }
    cout << "p1.amount: " << p1.get_amount() << endl;
}