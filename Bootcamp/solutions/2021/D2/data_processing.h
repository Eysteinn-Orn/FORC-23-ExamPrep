#include <iostream>
#include <vector>

struct DataPiece{
    int i;
    double d;
};

std::ostream &operator<<(std::ostream &out, const DataPiece &dp);

class DataStorage{
public:
    DataStorage();

    DataPiece get_next();
    bool is_empty();
private:
    std::vector<DataPiece> data;
};

class DataProcessor{
public:
    static int process_data(DataPiece &dp);
};
