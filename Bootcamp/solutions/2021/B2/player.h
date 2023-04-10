#ifndef PLAYER_H_987234
#define PLAYER_H_987234

#include <string>
#include <iostream>

using namespace std;

class Player {
public:
    // default constructor
    Player();

    // parameter constructor
    Player(string name, int number, double result);

    // copy constructor
    Player(const Player & other);

    // getters
    string get_name();
    int get_number();
    double get_result();

    // setters
    void set_name(string name);
    void set_number(int number);
    void set_result(double result);

    friend ostream & operator<<(ostream& os, const Player & obj);

private:
    string name;
    int number;
    double result;
};

#endif //PLAYER_H_987234