#include <iostream>
#include <vector>

struct DataPart{
    int i;
    double d;
};

std::ostream &operator<<(std::ostream &out, const DataPart &dp);

class DataStore{
public:
    DataStore();

    DataPart get_next();
    bool is_empty();
private:
    std::vector<DataPart> data;
};

class DataProcessing{
public:
    int process(DataPart &dp);
};
