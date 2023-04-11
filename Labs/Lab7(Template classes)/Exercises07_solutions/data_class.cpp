#include <iostream>
#include <string>

using namespace std;

#include "data_class.h"

DataClass::DataClass(int i, string s){
    this->i = i;
    this->s = s;
}
/*
bool DataClass::operator<(const DataClass &other){
    if(this->i == other.i){
        return this->s < other.s;
    }
    return this->i > other.i;
}
*/
DataClass::DataClass() : DataClass(0, ""){}

ostream& operator<<(ostream& out, const DataClass dc){
    out << "{" << dc.i << ":" << dc.s << "}";
    return out;
}