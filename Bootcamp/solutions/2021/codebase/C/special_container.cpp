#include "special_container.h"
#include <fstream>


void SpecialContainer::write_to_file(string filename) {
    ofstream file(filename, ios::binary);

    for(auto &p: this->store) {
        int key = p.first;
        NumericData value = p.second;

        file.write((char *)&key, sizeof(key));

        file.write((char *)&value, sizeof(value));
    }

    file.close();
}

void SpecialContainer::read_from_file(string filename) {
    ifstream file(filename, ios::binary);

    this->store.clear();

    while(!(file.eof() || file.peek() == EOF)) {
        int key;
        file.read((char *)&key, sizeof(key));

        NumericData value;
        file.read((char *)&value, sizeof(value));

        this->PutIntoContainer(key, value);
    }

    file.close();
}