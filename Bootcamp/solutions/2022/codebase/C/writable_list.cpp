#include "writable_list.h"
#include <fstream>

void WritableList::write_to_file(string filename) {
    ofstream file(filename, ios::binary);

    for(auto &p: this->pairs) {
        auto label = p.first;
        auto data = p.second;

        // write label
        int label_len = label.size();
        file.write((char *)&label_len, sizeof(label_len));

        file.write(label.c_str(), label.size());

        file.write((char *)&data, sizeof(data));
    }

    file.close();
    
}

void WritableList::read_from_file(string filename) {
    ifstream file(filename, ios::binary);

    this->pairs.clear();

    while(!(file.eof() || file.peek() == EOF)) {
        int label_len;
        file.read((char *)&label_len, sizeof(label_len));

        char * label_chars = new char[label_len];

        file.read(label_chars, label_len);

        string label(label_chars, label_len);

        delete[] label_chars;

        NumericData data;
        file.read((char *)&data, sizeof(data));
        this->pairs.push_back(make_pair(
            label, data
        ));
    }

    file.close();
}