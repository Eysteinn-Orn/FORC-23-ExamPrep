#include <iostream>

#include "player.h"
using namespace std;

int main(){
    Player p1;
    cout << p1 << endl;
    Player p2("einar", 7, 12.3);
    cout << p2 << endl;
    p1.set_name("kari");
    p1.set_number(23);
    p1.set_result(8.7);
    cout << p1 << endl;
    Player p3(p2);
    cout << p3 << endl;
    p2.set_name("einar helgi");
    p3.set_name("skuli");
    p3.set_number(57);
    p3.set_result(11.0);
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
}