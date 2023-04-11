#include <iostream>
#include "statlist.h"

using namespace std;

int main(){
    StatList list;

    Stats stats;

    stats.games = 2;
    stats.home_runs = 5;
    stats.average_score = 2.3;
    list.append(stats);

    stats.games = 7;
    stats.home_runs = 3;
    stats.average_score = 0.6;
    list.append(stats);

    stats.games = 27;
    stats.home_runs = 8;
    stats.average_score = 1.8;
    list.append(stats);

    stats.games = 54;
    stats.home_runs = 0;
    stats.average_score = 3.1;
    list.append(stats);

    stats.games = 12;
    stats.home_runs = 1;
    stats.average_score = 1.7;
    list.append(stats);

    cout << list << endl;

    cout << "get_at(3): " << list.get_at(3) << endl;
    cout << "get_at(4): " << list.get_at(4) << endl;
    cout << "get_at(0): " << list.get_at(0) << endl;

    cout << endl;

    cout << "insert(3.3, 3)" << endl;
    stats.games = 3;
    stats.home_runs = 3;
    stats.average_score = 3.3;
    list.insert(stats, 3);
    cout << list << endl;

    cout << "insert(0.0, 0)" << endl;
    stats.games = 0;
    stats.home_runs = 0;
    stats.average_score = 0.0;
    list.insert(stats, 0);
    cout << list << endl;

    cout << "insert(7.7, 7)" << endl;
    stats.games = 7;
    stats.home_runs = 7;
    stats.average_score = 7.7;
    list.insert(stats, 7);
    cout << list << endl;

    cout << "remove(4)" << endl;
    list.remove(4);
    cout << list << endl;

    cout << "remove(6)" << endl;
    list.remove(6);
    cout << list << endl;

    cout << "remove(0)" << endl;
    list.remove(0);
    cout << list << endl;


    return 0;
}