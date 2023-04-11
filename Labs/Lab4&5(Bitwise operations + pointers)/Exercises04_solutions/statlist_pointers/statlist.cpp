#include <iostream>
#include "statlist.h"

using namespace std;

StatList::StatList(){
    capacity = 4;
    array = new Stats*[capacity];
    size = 0;
}

StatList::~StatList(){
    for(int i = 0; i < size; i++){
        delete array[i];
    }
    delete[] array;
}

void StatList::append(int games, int home_runs, double average_score){
    if(size == capacity){
        resize();
    }
    array[size++] = new Stats(games, home_runs, average_score);
}

Stats *StatList::get_at(int index){
    if(index < 0 || index >= size){
        return NULL;
    }
    return array[index];
}

void StatList::insert(int games, int home_runs, double average_score, int index){
    if(index < 0 || index > size){
        return;
    }
    if(size == capacity){
        resize();
    }
    for(int i = size; i > index; i--){
        array[i] = array[i - 1];
    }
    array[index] = new Stats(games, home_runs, average_score);
    ++size;
}

void StatList::remove(int index){
    if(index < 0 || index >= size){
        return;
    }
    delete array[index];
    for(int i = index + 1; i < size; i++){
        array[i - 1] = array[i];
    }
    --size;
}

void StatList::resize(){
    Stats **tmp_arr = new Stats*[capacity * 2];
    for(int i = 0; i < size; i++){
        tmp_arr[i] = array[i];
    }
    delete[] array;
    array = tmp_arr;
    capacity *= 2;
}

ostream& operator<<(ostream& out, const StatList& list){
    for(int i = 0; i < list.size; i++){
        out << *(list.array[i]) << "\n";
    }
    return out;
}

Stats::Stats(int games, int home_runs, double average_score){
    this->games = games;
    this->home_runs = home_runs;
    this->average_score = average_score;
}

ostream& operator<<(ostream& out, const Stats& stats){
    out << "STATS{games: " << stats.games << ", home_runs: " << stats.home_runs << ", average_score: " << stats.average_score << "}";
}