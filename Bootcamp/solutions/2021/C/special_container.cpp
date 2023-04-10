#include "special_container.h"
#include <fstream>

void SpecialContainer::write_to_file(string filename) {
    ofstream file(filename, ios::binary);

    for(auto &pair: this->store) {
        int key = pair.first;

        file.write((char*) &key, sizeof(key));

        NumericData data = pair.second;

        file.write((char *) &data, sizeof(data));
    }

    file.close();
}

void SpecialContainer::read_from_file(string filename) {
    ifstream file(filename, ios::binary);

    this->store.clear();

    while(!(file.eof() || file.peek() == EOF)) {
        int key;
        file.read((char*)&key, sizeof(key));

        NumericData data;
        file.read((char *)&data, sizeof(data));

        this->store[key] = data;
    }

    file.close();
}