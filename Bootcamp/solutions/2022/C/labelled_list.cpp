#include "labelled_list.h"


/***** USE THIS AS A HELPER IF NEEDED OR COPY CODE OR WHATEVER *****/
#include <iostream>
void print_data(NumericData nd){
    std::cout << "id:" << nd.id << ", place:" << nd.place << ", amount:" << nd.amount;
}

/***** IMPLEMENT YOUR OPERATIONS HERE *****/

void LabelledList::add(string label, NumericData data) {
    pair<string, NumericData> element = make_pair(label, data);
    this->pairs.push_back(element);
}

void LabelledList::print_list() {
    for(auto &p : this->pairs) {
        string label = p.first;
        NumericData data = p.second;
        std::cout << "(" << label << "): ";
        print_data(data);
        cout << endl;
    }
}

