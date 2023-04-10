#include <iostream>
#include <thread>
#include "data_processing.h"
#include <mutex>

using namespace std;

mutex print_mutex;
mutex access_mutex;

void process_data(int my_number, DataStorage &ds){
    print_mutex.lock();
    std::cout << "processor #" << my_number << " starting" << std::endl;
    print_mutex.unlock();

    while(true){
        
        access_mutex.lock();
        if(ds.is_empty()){
            access_mutex.unlock();
            return;
        }

        DataPiece dp = ds.get_next();
        access_mutex.unlock();

        print_mutex.lock();
        std::cout << "processor #" << my_number << " processing data: " << dp << std::endl;
        print_mutex.unlock();


        int result = DataProcessor::process_data(dp);

        print_mutex.lock();
        std::cout << "processor #" << my_number << " RESULT: " << result << std::endl;
        print_mutex.unlock();
    }

    print_mutex.lock();
    std::cout << "processor #" << my_number << " STOPPING" << std::endl;
    print_mutex.unlock();
}

int main(){
    DataStorage ds;

    vector<thread> threads;

    for(int i = 1; i <= 7; i++) {
        threads.push_back(thread(
            process_data, i, std::ref(ds)
        ));
    }

    for(auto &t: threads) {
        t.join();
    }

    return 0;
}