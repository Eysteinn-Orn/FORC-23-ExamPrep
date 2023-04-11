#include <iostream>
#include <string>

using namespace std;

class DataClass{
public:
    DataClass(int i, string s);
    DataClass();

    //bool operator<(const DataClass &other);

    friend ostream& operator<<(ostream& out, const DataClass dc);

    int i;
    string s;
};