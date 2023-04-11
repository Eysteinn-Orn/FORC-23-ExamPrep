#ifndef STAT_LIST_92836423
#define STAT_LIST_92836423

#include <iostream>

using namespace std;

class Stats{
public:
    Stats(int, int, double);
    friend ostream& operator<<(ostream& out, const Stats& stats);
private:
    int games;
    int home_runs;
    double average_score;
};


class StatList{
public:
    StatList();
    virtual ~StatList();

    void append(int games, int home_runs, double average_score);
    Stats *get_at(int index);

    void insert(int games, int home_runs, double average_score, int index);
    void remove(int index);

    friend ostream& operator<<(ostream& out, const StatList& list);

private:
    Stats **array;
    int capacity;
    int size;

    void resize();
};

#endif //STAT_LIST_92836423