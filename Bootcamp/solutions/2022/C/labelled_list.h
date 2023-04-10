#ifndef LABELLEDLIST_H_77447345
#define LABELLEDLIST_H_77447345
#include <string>
#include <vector>

using namespace std;

struct NumericData{
    int id;
    int place;
    double amount;
};

//TODO: Implement LabelledList

class LabelledList {
public:
    void add(string label, NumericData data);
    void print_list();

protected:
    vector<pair<string, NumericData>> pairs;
};

#endif //LABELLEDLIST_H_77447345