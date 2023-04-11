#ifndef PLAYER_H_987234
#define PLAYER_H_987234

#include <iostream>
#include <string>

class Player{
public:
    Player();
    Player(std::string name, int number, double result);
    Player(const Player &player);

    void set_name(std::string name);
    void set_number(int number);
    void set_result(double result);

    std::string get_name();
    int get_number();
    double get_result();

    friend std::ostream &operator<<(std::ostream &out, Player player);

private:
    std::string name;
    int number;
    double result;
};

#endif //PLAYER_H_987234