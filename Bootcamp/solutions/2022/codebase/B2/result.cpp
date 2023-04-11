#include "result.h"

Result::Result(){
    this->analyst = "";
    this->count = 0;
    this->amount = 0.0;
    this->confirmed = false;
}

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

Result::Result(const Result & obj) {
    this->analyst = obj.analyst;
    this->count = obj.count;
    this->amount = obj.amount;
    this->confirmed = obj.confirmed;   
}


// getters
string Result::get_analyst() { 
    return this->analyst; 
}

int Result::get_count() { return this->count; }

double Result::get_amount() { return this->amount; }

bool Result::get_confirmed() { return this->confirmed; }

// setters
void Result::set_analyst(string analyst) { this->analyst = analyst; }

void Result::set_count(int count) { this->count = count; }

void Result::set_amount(double amount) { this->amount = amount; }

void Result::set_confirmed(bool confirmed) { this->confirmed = confirmed; }

ostream & operator<<(ostream & os, Result & obj) {

    bool confirmed = obj.get_confirmed();

    os << "Result("
       << "analyst=" << obj.get_analyst() << ","
       << "count=" << obj.get_count() << ","
       << "amount=" << obj.get_amount() << ","
       << (confirmed ? "": "not ") << "confirmed"
       << ")";

    return os;
}

