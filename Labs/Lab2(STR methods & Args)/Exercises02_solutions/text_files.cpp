#include <iostream>

#include <string.h>

#include <fstream>

using namespace std;

int main(){
    char my_string[128];
    my_string[0] = '\0';

    ofstream fout;
    fout.open("textfile.txt");

    cout << "Write lines to write to a file.\nEnter 'exit' to stop" << endl;

    while(strcmp(my_string, "exit") != 0){
        //cout << my_string << endl;
        fout << my_string << endl;
        cin >> my_string;
    }

    fout.close();

    ifstream fin;
    fin.open("textfile.txt");

    while(!fin.eof()){
        fin >> my_string;
        if(!fin.eof()){
            cout << my_string << endl;
        }
    }

    fin.close();

    return 0;
}
