#ifndef ADDABLE_H_4457345
#define ADDABLE_H_4457345

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
T add(T t1, T t2) {
    return t1 + t2;
}

class Addable {
public:
    Addable(int n, double x);
    
    Addable operator+(const Addable& other) const;

    friend ostream & operator<<(ostream & os, const Addable & obj);

    static vector<Addable> add_and_return(int num_pairs);

    static void print_addables_to_terminal(vector<Addable> addables);

    static void write_addables_to_file(string filename, vector<Addable> addables);

    static vector<Addable> read_addables_from_file(string filename);

private:
    int n;
    double x;
};

#endif //ADDABLE_H_4457345