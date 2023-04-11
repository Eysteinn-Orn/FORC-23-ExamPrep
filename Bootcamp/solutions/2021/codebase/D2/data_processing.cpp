#include "data_processing.h"
#include <chrono>
#include <thread>
#include <math.h>

std::ostream &operator<<(std::ostream &out, const DataPiece &dp){
    out << "(" << dp.i << "; " << dp.d << ")";
    return out;
}

DataStorage::DataStorage(){
    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    for(int i = 0; i < 100; i++){
        DataPiece dp;
        dp.i = rand() % 90 + 10;
        dp.d = (double)(rand() % 90000 + 10000) / (double)pow(10, rand() % 5 + 1);
        this->data.push_back(dp);
    }
}

DataPiece DataStorage::get_next(){
    DataPiece dp = this->data.back();
    this->data.pop_back();
    return dp;
}

bool DataStorage::is_empty(){
    return this->data.empty();
}

int DataProcessor::process_data(DataPiece &dp){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    return dp.i * 100 + dp.d * 1000;
}
