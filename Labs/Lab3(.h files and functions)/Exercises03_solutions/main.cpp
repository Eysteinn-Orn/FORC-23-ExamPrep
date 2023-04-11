#include <iostream>

#include "my_helpers.h"

using namespace std;

int main(){
    char some_array[10];
    some_array[0] = 1;
    some_array[1] = 5;
    some_array[2] = 6;
    some_array[3] = 8;
    some_array[4] = 12;
    some_array[5] = 14;
    some_array[6] = 15;
    some_array[7] = 16;
    some_array[8] = 21;
    some_array[9] = 23;

    int found_index;
    int comparison_count;

    for(int i = 0; i < 25; i++){
        if(linear_search(some_array, i, 10, found_index, comparison_count)){
            cout << "The value " << i << " was found in " << comparison_count << " comparisons at index " << found_index << endl;
        }
        else{
            cout << "The value " << i << " was NOT found after " << comparison_count << " comparisons" << endl;
        }
    }
    cout << endl;

    for(int i = 0; i < 25; i++){
        if(binary_search(some_array, i, 10, found_index, comparison_count)){
            cout << "The value " << i << " was found in " << comparison_count << " comparisons at index " << found_index << endl;
        }
        else{
            cout << "The value " << i << " was NOT found after " << comparison_count << " comparisons" << endl;
        }
        cout << endl;
    }
}