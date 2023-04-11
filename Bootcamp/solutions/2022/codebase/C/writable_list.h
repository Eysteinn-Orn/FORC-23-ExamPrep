#ifndef WRITABLELIST_H_224457345
#define WRITABLELIST_H_224457345

#include <string>
#include "labelled_list.h"

using namespace std;

class WritableList : public LabelledList {
public:
    void write_to_file(string filename);
    void read_from_file(string filename);
};

#endif //WRITABLELIST_H_224457345