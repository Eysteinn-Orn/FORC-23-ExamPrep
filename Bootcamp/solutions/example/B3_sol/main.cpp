#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void read_file_and_add() {
    // read filename from stdin
    string filename;
    cout << "Filename: ";
    cin >> filename;

    ifstream file(filename);
    
    while(!file.eof()) {
        int a, b;
        file >> a >> b;
        int sum = a + b;
        cout << "The sum of " << a << " and " << b << " is " << sum << endl;
    }

    file.close();
}

int main(){
    read_file_and_add();
    return 0;
}