#include <iostream>
#include <thread>
#include <mutex>
#include "data_processing.h"

std::mutex print_mutex;
std::mutex ds_mutex;

void process_stuff(DataStore &ds, DataProcessing dproc, int my_number){
    print_mutex.lock();
    std::cout << "Processor #" << my_number << " starting" << std::endl;
    print_mutex.unlock();

    while(true){
        ds_mutex.lock();
        if(ds.is_empty()){
            ds_mutex.unlock();
            break;
        }

        DataPart dp = ds.get_next();
        ds_mutex.unlock();

        print_mutex.lock();
        std::cout << "Processor #" << my_number << " processing data: " << dp << std::endl;
        print_mutex.unlock();

        int result = dproc.process(dp);

        print_mutex.lock();
        std::cout << "Processor #" << my_number << " RESULT: " << result << std::endl;
        print_mutex.unlock();
    }
    print_mutex.lock();
    std::cout << "Processor #" << my_number << " STOPPING" << std::endl;
    print_mutex.unlock();
}

int main(){
    DataStore ds;
    DataProcessing dproc;

    std::vector<std::thread> threads;

    for(int i = 1; i <= 5; i++){
        threads.push_back(std::thread(
            process_stuff,
            std::ref(ds), dproc, i
        ));
    }

    for(auto &t: threads) {
        t.join();
    }

    return 0;
}