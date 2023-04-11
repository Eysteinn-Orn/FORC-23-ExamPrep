#include "adder.h"

Adder::Adder(int n) {
    this->n = n;
}

int Adder::add(int n) {
    return this->n + n;
}