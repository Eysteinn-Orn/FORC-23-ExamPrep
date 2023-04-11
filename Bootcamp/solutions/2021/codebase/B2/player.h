#ifndef PLAYER_H_987234
#define PLAYER_H_987234

#include <string>
#include <iostream>

using namespace std;

class Player {
public:
    Player();
    Player(string name, int number, double result);
    Player(const Player & player);

    // getters
    string get_name();
    int get_number();
    double get_result();

    // setters
    void set_name(string new_name);
    void set_number(int number);
    void set_result(double result);

    friend ostream & operator<<(ostream & os, const Player & obj);

private:
    string name;
    int number;
    double result;
};

#endif //PLAYER_H_987234