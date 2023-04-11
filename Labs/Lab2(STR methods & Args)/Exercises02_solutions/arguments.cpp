#include <iostream>

#include <stdlib.h>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]){
    // for(int i = 0; i < argc; i++){
    //     cout << argv[i] << endl;
    // }

    char name[36];
    strcpy(name, "Nameless");
    int number = 23;
    double height = 1.5;

    if(argc > 1){
        strcpy(name, argv[1]);
    }
    if(argc > 2){
        number = atoi(argv[2]);
    }
    if(argc > 3){
        height = atof(argv[3]);
    }

    cout << "Name:    " << name << endl;
    cout << "Number:  " << number << endl;
    cout << "Height:  " << height << " m" << endl;
}