#include <iostream>
#include <string.h>

using namespace std;

bool compare_strings(char * s1, char * s2) {
    bool identical = strcmp(s1, s2) == 0;

    if(identical){
        return true;
    }

    int s1_length = strlen(s1);
    int s2_length = strlen(s2);

    int smaller = min(s1_length, s2_length);
    int larger = max(s1_length, s2_length);

    cout << "Indexes that differ:";
    for(int i = 0; i < larger; i++){
        if(i < smaller){
            if(s1[i] != s2[i]){
                cout << " " << i;
            }
        } else {
            cout << " " << i;
        }
    }
    cout << endl;

    cout << "Length difference: " << larger - smaller << endl;

    return false;
}

int main(){
    char str1[1024];
    char str2[1024];
    cout << "Enter a string: ";
    cin >> str1;
    cout << "Enter a string: ";
    cin >> str2;
    if(compare_strings(str1, str2)){
        cout << "The strings are identical" << endl;
    }
    return 0;
}