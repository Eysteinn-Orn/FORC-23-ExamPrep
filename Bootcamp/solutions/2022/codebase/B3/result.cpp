#include "result.h"

// default constructor
Result::Result() {
    this->analyst = "";
    this->count = 0;
    this->amount = 0;
    this->confirmed = false;
}

// parameter constructor
Result::Result(
    string analyst,
    int count,
    double amount,
    bool confirmed
){
    this->analyst = analyst;
    this->count = count;
    this->amount = amount;
    this->confirmed = confirmed;
}

// copy constructor
Result::Result(const Result & other){
    this->analyst = other.analyst;
    this->count = other.count;
    this->amount = other.amount;
    this->confirmed = other.confirmed;
}

// getters
string Result::get_analyst(){
    return this->analyst;
}

int Result::get_count() {
    return this->count;
}

double Result::get_amount() {
    return this->amount;
}

bool Result::get_confirmed() {
    return this->confirmed;
}

// setters
void Result::set_analyst(string analyst) {
    this->analyst = analyst;
}

void Result::set_count(int count) {
    this->count = count;
}

void Result::set_amount(double amount){
    this->amount = amount;
}

void Result::set_confirmed(bool confirmed){
    this->confirmed = confirmed;
}

// stream operator
ostream & operator<<(ostream & os, const Result & res) {
    os << "Result("
       << "analyst=\"" << res.analyst << "\","
       << "count=" << res.count << ","
       << "amount=" << res.amount << ","
       << (res.confirmed ? "" : "not ") << "confirmed"
       << ")";

    return os;
}