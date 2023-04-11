#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class DataClass{
public:
    DataClass(int number = 0, char letter = '\0'){this->number = number; this->letter = letter;};

    friend ostream& operator<<(ostream& out, const DataClass &dc){
        out << "{" << dc.number << ":" << dc.letter << "}";
        return out;
    }

private:
    int number;
    char letter;
};

int main(){
    ofstream output_file("my_file.bnr", ios::binary);

    int some_integer = 25984;
    //note that it’s the reference being typecast, not the integer itself
    char *bytes = (char *)(&some_integer);
    output_file.write(bytes, sizeof(int));

    DataClass some_data(93478, 'k');
    bytes = (char *)(&some_data);
    output_file.write(bytes, sizeof(DataClass)); // or
    output_file.write((char *)(&some_data), sizeof(DataClass));

    char *bytes_copy = new char[sizeof(DataClass)];
    memcpy(bytes_copy, (void *)(&some_data), sizeof(DataClass));

    DataClass *some_data_pointer = new DataClass(223, 'p');
    //Here we typecast the pointer.
    //No need for an extra reference since the pointer is already a memory location
    bytes = (char *)some_data_pointer;
    output_file.write(bytes, sizeof(DataClass)); // or
    output_file.write((char *)some_data_pointer, sizeof(DataClass));

    memcpy(some_data_pointer, bytes_copy, sizeof(DataClass));
    cout << *some_data_pointer << endl;
    
    output_file.write((char *)some_data_pointer, sizeof(DataClass));


    output_file.close();

    ifstream input_file("my_file.bnr", ios::binary);

    int other_integer;
    input_file.read((char *)(&other_integer), sizeof(int));
    cout << other_integer << endl;

    //DataClass some_data;
    input_file.read((char *)(&some_data), sizeof(DataClass));
    cout << some_data << endl;

    input_file.read(bytes, sizeof(DataClass));
    some_data_pointer = (DataClass *)bytes;
    cout << *some_data_pointer << endl;

    //DataClass some_data;
    //char *bytes = new char[sizeof(DataClass)];
    input_file.read(bytes, sizeof(DataClass));
    memcpy((void *)(&some_data), bytes, sizeof(DataClass));
    cout << some_data << endl;

    //DataClass *some_data_pointer = new DataClass();
    input_file.read((char *)some_data_pointer, sizeof(DataClass));
    cout << some_data << endl;

    //DataClass *some_data_pointer = new DataClass();
    bytes = new char[sizeof(DataClass)];
    input_file.read(bytes, sizeof(DataClass));
    memcpy((void *)some_data_pointer, bytes, sizeof(DataClass));
    cout << some_data << endl;
}