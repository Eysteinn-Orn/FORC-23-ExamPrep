#include <iostream>
#include <string.h>

//TODO: Implement compare_strings

using namespace std;

bool compare_strings(char * s1, char * s2) {

    bool identical = strcmp(s1, s2) == 0;

    if(!identical){
        int s1_len = strlen(s1);
        int s2_len = strlen(s2);

        int smaller = min(s1_len, s2_len);
        int larger = max(s1_len, s2_len);

        cout << "Indexes that differ:";
        for(int i = 0; i < larger; i++) {

            if(i >= smaller) {
                cout << " " << i;
            } 
            else if(s1[i] != s2[i]) {
                cout << " " << i;
            }

        }
        cout << endl;

        int length_diff = larger - smaller;

        cout << "Length diff: " << length_diff << endl;
    }

    return identical;
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