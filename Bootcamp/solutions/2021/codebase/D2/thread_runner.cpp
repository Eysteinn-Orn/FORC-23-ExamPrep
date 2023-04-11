#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include "data_processing.h"

std::mutex print_mutex;
std::mutex ds_mutex;

void process_data(int my_number, DataStorage &ds){

    print_mutex.lock();
    std::cout << "processor #" << my_number << " starting" << std::endl;
    print_mutex.unlock();

    while(true){
        ds_mutex.lock();
        if(ds.is_empty()){
            ds_mutex.unlock();
            break;
        }

        DataPiece dp = ds.get_next();
        ds_mutex.unlock();

        print_mutex.lock();
        std::cout << "processor #" << my_number << " processing data: " << dp << std::endl;
        print_mutex.unlock();

        int result = DataProcessor::process_data(dp);

        print_mutex.lock();
        std::cout << "processor #" << my_number << " RESULT: " << result << std::endl;
        print_mutex.unlock();
    }
    print_mutex.lock();
    std::cout << "processor #" << my_number << " STOPPING" << std::endl << std::flush;
    print_mutex.unlock();
}

int main(){
    DataStorage ds;

    std::vector<std::thread> threads;

    for(int i = 1; i <=7; i++){
        threads.push_back(
            std::thread(
                process_data,
                i, std::ref(ds)
            )
        );
    }

    for(auto &t: threads) {
        t.join();
    }

    return 0;
}