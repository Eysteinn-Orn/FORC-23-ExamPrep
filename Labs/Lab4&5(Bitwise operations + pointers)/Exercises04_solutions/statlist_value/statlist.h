#ifndef STAT_LIST_92836423
#define STAT_LIST_92836423

#include <iostream>

using namespace std;

struct Stats{
    int games;
    int home_runs;
    double average_score;
};

ostream& operator<<(ostream& out, const Stats& stats);

class StatList{
public:
    StatList();
    virtual ~StatList();

    void append(const Stats& stats);
    Stats get_at(int index);

    void insert(const Stats& stats, int index);
    void remove(int index);

    friend ostream& operator<<(ostream& out, const StatList& list);

private:
    Stats *array;
    int capacity;
    int size;

    void resize();
};

#endif //STAT_LIST_92836423