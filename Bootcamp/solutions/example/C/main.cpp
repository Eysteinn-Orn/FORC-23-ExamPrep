#include <iostream>
#include "addable.h"
using namespace std;

int main(){
    double a, b;
    cout << "Enter a real number: ";
    cin >> a;
    cout << "Enter a real number: ";
    cin >> b;
    cout << "The sum of the numbers is " << add(a, b) << endl;
    std::string s1, s2;
    cout << "Enter a string: ";
    cin >> s1;
    cout << "Enter a string: ";
    cin >> s2;
    cout << "The sum of the integers is " << add(s1, s2) << endl;
    Addable add1(23, 0.45), add2(12, 0.3);
    cout << "Addable 1: " << add1 << endl;
    cout << "Addable 2: " << add2 << endl;
    cout << "The sum of the addables is " << add(add1, add2) << endl;

    auto addable_collection = Addable::add_and_return(3);
    cout << "ORIGINALS:" << endl;
    Addable::print_addables_to_terminal(addable_collection);
    Addable::write_addables_to_file("addable_file_01.add", addable_collection);
    auto addables_from_file = Addable::read_addables_from_file("addable_file_01.add");
    cout << "FROM FILE:" << endl;
    Addable::print_addables_to_terminal(addables_from_file);

    return 0;
}