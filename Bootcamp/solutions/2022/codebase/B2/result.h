#ifndef RESULT_H_11987234
#define RESULT_H_11987234
#include <string>
#include <iostream>

using namespace std;

class Result {
public:
    Result();
    Result(
        string analyst,
        int count,
        double amount,
        bool confirmed
    );

    Result(const Result & obj);

    // getters
    string get_analyst();
    int get_count();
    double get_amount();
    bool get_confirmed();

    // setters
    void set_analyst(string analyst);
    void set_count(int count);
    void set_amount(double amount);
    void set_confirmed(bool confirmed);

private:
    string analyst;
    int count;
    double amount;
    bool confirmed;
};

ostream & operator<<(ostream & os, Result & obj);

#endif //RESULT_H_11987234