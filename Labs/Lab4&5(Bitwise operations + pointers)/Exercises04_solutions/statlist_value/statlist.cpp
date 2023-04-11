#include <iostream>
#include "statlist.h"

using namespace std;

StatList::StatList(){
    capacity = 4;
    array = new Stats[capacity];
    size = 0;
}

StatList::~StatList(){
    delete[] array;
}

void StatList::append(const Stats& stats){
    if(size == capacity){
        resize();
    }
    array[size++] = stats;
}

Stats StatList::get_at(int index){
    if(index < 0 || index >= size){
        Stats ret_stats;
        ret_stats.games = 0;
        ret_stats.home_runs = 0;
        ret_stats.average_score = 0.0;
        return ret_stats;
    }
    return array[index];
}

void StatList::insert(const Stats& stats, int index){
    if(index < 0 || index > size){
        return;
    }
    if(size == capacity){
        resize();
    }
    for(int i = size; i > index; i--){
        array[i] = array[i - 1];
    }
    array[index] = stats;
    ++size;
}

void StatList::remove(int index){
    if(index < 0 || index >= size){
        return;
    }
    for(int i = index + 1; i < size; i++){
        array[i - 1] = array[i];
    }
    --size;
}

void StatList::resize(){
    Stats *tmp_arr = new Stats[capacity * 2];
    for(int i = 0; i < size; i++){
        tmp_arr[i] = array[i];
    }
    delete[] array;
    array = tmp_arr;
    capacity *= 2;
}

ostream& operator<<(ostream& out, const StatList& list){
    for(int i = 0; i < list.size; i++){
        out << list.array[i] << "\n";
    }
    return out;
}

ostream& operator<<(ostream& out, const Stats& stats){
    out << "STATS{games: " << stats.games << ", home_runs: " << stats.home_runs << ", average_score: " << stats.average_score << "}";
}