#include <iostream>

using namespace std;

int main(){
    char c;
    while(c != 'q'){
        cout << "Enter a character: ";
        cin >> c;
        if(c == 'a'){
            cout << "You have entered the first letter of the alphabet." << endl;
        }
        else if(c == 'o'){
            cout << "\'o\' could refer to \"object\" or maybe \"output\"." << endl;
        }
        else if(c == 'c'){
            cout << "CONTROL CHARACTER!" << endl;
        }
        else if(c != 'q'){
            cout << "This is an unknown input: " << c << "\nTry \'a\', \'c\', \'o\' or \'q\' to quit." << endl;
        }
    }
}