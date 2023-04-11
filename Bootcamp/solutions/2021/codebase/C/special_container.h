#ifndef SPECIALCONTAINER_H_4457345
#define SPECIALCONTAINER_H_4457345

#include <string>
#include "keyed_container.h"

using namespace std;

struct NumericData{
    int id;
    int place;
    double amount;
};

class SpecialContainer : public KeyedContainer<int, NumericData> {
public:
    void write_to_file(string filename);
    void read_from_file(string filename);
};


#endif //SPECIALCONTAINER_H_4457345