#include "player.h"


// default constructor
Player::Player(){
    this->name = "";
    this->number = 0;
    this->result = 0.0;
}

// parameter constructor
Player::Player(string name, int number, double result) {
    this->name = name;
    this->number = number;
    this->result = result;
}

// copy constructor
Player::Player(const Player & other) : name(other.name), number(other.number), result(other.result) {}

// Player::Player(const Player & other)
// {
//     this->name = other.name;
//     this->number = other.number;
//     this->result = other.result;
// }

// getters
string Player::get_name(){
    return this->name;
}

int Player::get_number(){
    return this->number;
}

double Player::get_result(){
    return this->result;
}

// setters
void Player::set_name(string name){
    this->name = name;
}

void Player::set_number(int number) {
    this->number = number;
}

void Player::set_result(double result) {
    this->result = result;
}


ostream & operator<<(ostream& os, const Player & obj) {
    os << "Player(" 
        << "name=\"" << obj.name << "\","
        << "number=" << obj.number << ","
        << "result=" << obj.result
        << ")";

    return os;
}

