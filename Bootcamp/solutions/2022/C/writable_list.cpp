#include "writable_list.h"
#include <fstream>

void WritableList::write_to_file(string filename) {
    ofstream file(filename, ios::binary);

    for(auto &p: this->pairs) {
        string label = p.first;
        int strlen = label.length();

        file.write((char *) &strlen, sizeof(strlen));
        file.write(label.c_str(), strlen);

        NumericData data = p.second;

        file.write((char *) &data, sizeof(data));
    }

    file.close();
}

void WritableList::read_from_file(string filename) {
    ifstream file(filename, ios::binary);

    this->pairs.clear();
    while(!(file.eof() || file.peek() == EOF)) {
        int label_length;

        file.read((char *) &label_length, sizeof(label_length));

        char buffer[label_length];

        file.read((char *) buffer, label_length);

        string label(buffer, label_length);

        NumericData data;
        file.read((char *) &data, sizeof(data));

        this->add(label, data);
    }

    file.close();
}
