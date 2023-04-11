#include "addable.h"
#include <random>
#include <fstream>

Addable::Addable(int n, double x) {
    this->n = n;
    this->x = x;
}

Addable Addable::operator+(const Addable & other) const {
    return Addable(
        this->n + other.n,
        this->x + other.x
    );
}


ostream & operator<<(ostream & os, const Addable & obj) {
    os << "Addable("
       << "n=" << obj.n << ","
       << "x=" << obj.x
       << ")";

    return os;
}

vector<Addable> Addable::add_and_return(int num_pairs) {
    vector<Addable> addables;

    for(int i = 0; i < num_pairs; i++) {
        int n1 = rand() % 10000;
        int n2 = rand() % 10000;

        double x1 = ((double) rand()) / ((double) RAND_MAX);
        double x2 = ((double) rand()) / ((double) RAND_MAX);

        Addable addable1(
            n1, x1
        );

        Addable addable2(
            n2, x2
        );

        Addable added = add(addable1, addable2);

        addables.push_back(added);
    }

    return addables;
}

void Addable::print_addables_to_terminal(vector<Addable> & addables) {
    for(Addable &a: addables) {
        cout << a << endl;
    }
    cout << flush;
}


void Addable::write_addables_to_file(string filename,vector<Addable> addables) {
    ofstream file(filename, ios::binary);

    int count = addables.size();

    file.write((char *)&count, sizeof(count));

    for(Addable &a: addables) {
        int n = a.n;
        file.write((char *)&n, sizeof(n));
        double x = a.x;
        file.write((char *)&x, sizeof(x));
    }

    file.close();
}

vector<Addable> Addable::read_addables_from_file(string filename) {
    ifstream file(filename, ios::binary);

    int count;
    file.read((char *)&count, sizeof(count));

    vector<Addable> addables;

    for(int i=0; i < count; i++) {
        int n;
        file.read((char *)&n, sizeof(n));
        double x;
        file.read((char *)&x, sizeof(x));

        Addable addable(
            n, x
        );

        addables.push_back(addable);
    }

    file.close();
    return addables;
}