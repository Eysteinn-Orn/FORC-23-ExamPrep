#include "player.h"

Player::Player(){
    this->name = "";
    this->number = 0;
    this->result = 0.0;
}

Player::Player(std::string name, int number, double result){
    this->name = name;
    this->number = number;
    this->result = result;
}

Player::Player(const Player &player){
    this->name = player.name;
    this->number = player.number;
    this->result = player.result;
}

std::string Player::get_name(){
    return this->name;
}

int Player::get_number(){
    return this->number;
}

double Player::get_result(){
    return this->result;
}

void Player::set_name(std::string name){
    this->name = name;
}

void Player::set_number(int number){
    this->number = number;
}

void Player::set_result(double result){
    this->result = result;
}

std::ostream &operator<<(std::ostream &out, Player player){
    out << "{name:" << player.name << ",number:" << player.number << ",result:" << player.result << "}";
    return out;
}
