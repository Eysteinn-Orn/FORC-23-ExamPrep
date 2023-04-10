#include <fstream>
#include "addable.h"


Addable::Addable(int n, double x) {
    this->n = n;
    this->x = x;
}

ostream & operator<<(ostream & os, const Addable & obj) {
    os << "Addable("
       << "n=" << obj.n << ","
       << "x=" << obj.x
       << ")";

    return os;
}

Addable Addable::operator+(const Addable& other) const {
    return Addable(
        this->n + other.n,
        this->x + other.x
    );
}

vector<Addable> Addable::add_and_return(int num_pairs) {
    vector<Addable> addables;

    for(int i = 0; i < num_pairs; i++) {
        int n1 = rand() % 1000;
        int n2 = rand() % 1000;

        double x1 = (double)rand() / (double) RAND_MAX;
        double x2 = (double)rand() / (double) RAND_MAX;
        
        Addable a1 = Addable(n1, x1);
        Addable a2 = Addable(n2, x2);

        Addable added = add(a1, a2);

        addables.push_back(added);
    }

    return addables;
}

void Addable::print_addables_to_terminal(vector<Addable> addables) {
    for(auto &a: addables){
        cout << a << endl;
    }
}


void Addable::write_addables_to_file(string filename, vector<Addable> addables) {
    ofstream file(filename, ios::binary);
    for(auto &addable: addables) {
        file.write((char *) &addable.n, sizeof(addable.n));
        file.write((char *) &addable.x, sizeof(addable.x));
    }
    file.close();
}

vector<Addable> Addable::read_addables_from_file(string filename) {
    ifstream file(filename, ios::binary);

    vector<Addable> addables;

    while(!(file.eof() || file.peek() == EOF)) {
        int n;
        file.read((char *) &n, sizeof(n));

        double x;
        file.read((char *)&x, sizeof(x));

        Addable addable(n, x);
        addables.push_back(addable);
    }

    file.close();

    return addables;
}
