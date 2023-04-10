#include "adder.h"


Adder::Adder(int number){
    this->number = number;
}

int Adder::add(int number) {
    return this->number + number;
}