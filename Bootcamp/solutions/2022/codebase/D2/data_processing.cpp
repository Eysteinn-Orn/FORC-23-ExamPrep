#include "data_processing.h"
#include <chrono>
#include <thread>
#include <math.h>

std::ostream &operator<<(std::ostream &out, const DataPart &dp){
    out << "(" << dp.i << "; " << dp.d << ")";
    return out;
}

DataStore::DataStore(){
    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    for(int i = 0; i < 100; i++){
        DataPart dp;
        dp.i = rand() % 90 + 10;
        dp.d = (double)(rand() % 90000 + 10000) / (double)pow(10, rand() % 5 + 1);
        this->data.push_back(dp);
    }
}

DataPart DataStore::get_next(){
    DataPart dp = this->data.back();
    this->data.pop_back();
    return dp;
}

bool DataStore::is_empty(){
    return this->data.empty();
}

int DataProcessing::process(DataPart &dp){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    return dp.i * 100 + dp.d * 1000;
}
