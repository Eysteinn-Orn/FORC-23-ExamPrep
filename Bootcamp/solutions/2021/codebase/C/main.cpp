#include <iostream>

#include "keyed_container.h"
#include "special_container.h"
using namespace std;

NumericData make_data(int id, int p, double a){
    NumericData nd;
    nd.id = id;
    nd.place = p;
    nd.amount = a;
    return nd;
}

void print_data(NumericData nd){
    cout << "id:" << nd.id << ", place:" << nd.place << ", amount:" << nd.amount << endl;
}

int main(){
    cout << "\nTESTING KEYED CONTAINER\n" << endl;
    KeyedContainer<int, string> cont;
    cont.PutIntoContainer(10, "Dagny");
    cont.PutIntoContainer(17, "Karitas");
    cont.PutIntoContainer(2, "Glodis");
    cont.PutIntoContainer(5, "Hallbera");
    cont.PutIntoContainer(14, "Gudrun");
    cont.PutIntoContainer(12, "Cecelia");
    cont.PutIntoContainer(1, "Sandra");
    cont.PutIntoContainer(16, "Elin");
    cont.PutIntoContainer(23, "Sveindis");

    int player_number = -1;

    //I will not test with non-existing values in this exam, although this would be important in real life!
    cout << "Player number 23 is " << cont.GetFromContainer(23) << endl;
    cout << "Player number 2 is " << cont.GetFromContainer(2) << endl;
    cout << "Player number 10 is " << cont.GetFromContainer(10) << endl;
    cout << "Player number 1 is " << cont.GetFromContainer(1) << endl;
    cout << "Player number 16 is " << cont.GetFromContainer(16) << endl;



    cout << "\nTESTING SPECIAL CONTAINER\n" << endl;
    SpecialContainer spec;

    spec.PutIntoContainer(1, make_data(11, 23, 34.765));
    spec.PutIntoContainer(2, make_data(12, 11, 45.73));
    spec.PutIntoContainer(3, make_data(13, 567, 123.2));
    spec.PutIntoContainer(4, make_data(14, 132, 1.41234));
    spec.PutIntoContainer(5, make_data(15, 343, 232.543));
    print_data(spec.GetFromContainer(3));
    print_data(spec.GetFromContainer(4));
    print_data(spec.GetFromContainer(2));
    print_data(spec.GetFromContainer(1));
    print_data(spec.GetFromContainer(5));

    cout << "\nTESTING SPECIAL CONTAINER FILE FUNCTIONALITY\n" << endl;

    spec.write_to_file("binary_file_tester.nd");

    SpecialContainer special_read;
    special_read.read_from_file("binary_file_tester.nd");
    print_data(special_read.GetFromContainer(3));
    print_data(special_read.GetFromContainer(4));
    print_data(special_read.GetFromContainer(2));
    print_data(special_read.GetFromContainer(1));
    print_data(special_read.GetFromContainer(5));

    return 0;
}