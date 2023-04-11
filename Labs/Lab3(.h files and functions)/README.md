# Fimmtudagur - dæmatími 3 - æfingaverkefni
Students are welcome to work on their PA1 assignment during lab class and get assistance on that.

Here are the practice exercises:

Start by making a .cpp file for your main function.

Then make a .h file for your other function declarations and a .cpp for the implementations of your functions.

Now declare a function called circumference that returns a double and takes a double as a parameter.  It takes the radius of a circle and returns the circle's circumference (ummál).  Declare the function in the .h file (with no {}, just a semicolon at the end).

Now make an implementation of the circumference function in your .cpp file (not the same on as main() is in).

\#include your .h file in the main .cpp and call the function in your main() function.  Compile all (both) the .cpp files together and run the executable.  Experiment and test.

Next read this main() function:
```cpp
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

    for(int i = 0; i < 25; i++){ // 10 is the array length.  You need to send that to the operation so it knows the boundaries.
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
```
You can see that it includes my_helpers.h and calls linear_search and binary_search.  You can decide which one you implement or if you implement both.  No need for recursion in the linear search, but for the binary search I recommend recursion and always sending the same array, but changing the values of left and right to decide where each iteration is bounded.

The main thing here is that you want not only to receive the boolean value for whether the value was found or not, but also to get back in which index it was found and how many comparisons were made.

Make the .h and .cpp files needed and declare and implement functions that can do this correctly.  Remember to use reference variables where you need them, but don't overuse them.  You can send the array as a parameter like this: void some_function(char some_array[], float something_else);

This is the output from the teacher's program (intermediate print lines included for fun and clarity - no need for students to have those):
```cmd
The value 0 was NOT found after 10 comparisons
The value 1 was found in 1 comparisons at index 0
The value 2 was NOT found after 10 comparisons
The value 3 was NOT found after 10 comparisons
The value 4 was NOT found after 10 comparisons
The value 5 was found in 2 comparisons at index 1
The value 6 was found in 3 comparisons at index 2
The value 7 was NOT found after 10 comparisons
The value 8 was found in 4 comparisons at index 3
The value 9 was NOT found after 10 comparisons
The value 10 was NOT found after 10 comparisons
The value 11 was NOT found after 10 comparisons
The value 12 was found in 5 comparisons at index 4
The value 13 was NOT found after 10 comparisons
The value 14 was found in 6 comparisons at index 5
The value 15 was found in 7 comparisons at index 6
The value 16 was found in 8 comparisons at index 7
The value 17 was NOT found after 10 comparisons
The value 18 was NOT found after 10 comparisons
The value 19 was NOT found after 10 comparisons
The value 20 was NOT found after 10 comparisons
The value 21 was found in 9 comparisons at index 8
The value 22 was NOT found after 10 comparisons
The value 23 was found in 10 comparisons at index 9
The value 24 was NOT found after 10 comparisons

recurring
going left 0 4 9
recurring
going left 0 1 3
recurring
bogus
The value 0 was NOT found after 2 comparisons

recurring
going left 0 4 9
recurring
going left 0 1 3
recurring
bogus
The value 1 was NOT found after 2 comparisons

recurring
going left 0 4 9
recurring
going left 0 1 3
recurring
bogus
The value 2 was NOT found after 2 comparisons

recurring
going left 0 4 9
recurring
going left 0 1 3
recurring
bogus
The value 3 was NOT found after 2 comparisons

recurring
going left 0 4 9
recurring
going left 0 1 3
recurring
bogus
The value 4 was NOT found after 2 comparisons

recurring
going left 0 4 9
recurring
Excellent!
The value 5 was found in 2 comparisons at index 1

recurring
going left 0 4 9
recurring
going right 0 1 3
recurring
Excellent!
The value 6 was found in 3 comparisons at index 2

recurring
going left 0 4 9
recurring
going right 0 1 3
recurring
going right 2 2 3
recurring
bogus
The value 7 was NOT found after 3 comparisons

recurring
going left 0 4 9
recurring
going right 0 1 3
recurring
going right 2 2 3
recurring
bogus
The value 8 was NOT found after 3 comparisons

recurring
going left 0 4 9
recurring
going right 0 1 3
recurring
going right 2 2 3
recurring
bogus
The value 9 was NOT found after 3 comparisons

recurring
going left 0 4 9
recurring
going right 0 1 3
recurring
going right 2 2 3
recurring
bogus
The value 10 was NOT found after 3 comparisons

recurring
going left 0 4 9
recurring
going right 0 1 3
recurring
going right 2 2 3
recurring
bogus
The value 11 was NOT found after 3 comparisons

recurring
Excellent!
The value 12 was found in 1 comparisons at index 4

recurring
going right 0 4 9
recurring
going left 5 7 9
recurring
bogus
The value 13 was NOT found after 3 comparisons

recurring
going right 0 4 9
recurring
going left 5 7 9
recurring
Excellent!
The value 14 was found in 3 comparisons at index 5

recurring
going right 0 4 9
recurring
going left 5 7 9
recurring
going right 5 5 6
recurring
bogus
The value 15 was NOT found after 3 comparisons

recurring
going right 0 4 9
recurring
Excellent!
The value 16 was found in 2 comparisons at index 7

recurring
going right 0 4 9
recurring
going right 5 7 9
recurring
bogus
The value 17 was NOT found after 3 comparisons

recurring
going right 0 4 9
recurring
going right 5 7 9
recurring
bogus
The value 18 was NOT found after 3 comparisons

recurring
going right 0 4 9
recurring
going right 5 7 9
recurring
bogus
The value 19 was NOT found after 3 comparisons

recurring
going right 0 4 9
recurring
going right 5 7 9
recurring
bogus
The value 20 was NOT found after 3 comparisons

recurring
going right 0 4 9
recurring
going right 5 7 9
recurring
Excellent!
The value 21 was found in 3 comparisons at index 8

recurring
going right 0 4 9
recurring
going right 5 7 9
recurring
going right 8 8 9
recurring
bogus
The value 22 was NOT found after 3 comparisons

recurring
going right 0 4 9
recurring
going right 5 7 9
recurring
going right 8 8 9
recurring
bogus
The value 23 was NOT found after 3 comparisons

recurring
going right 0 4 9
recurring
going right 5 7 9
recurring
going right 8 8 9
recurring
bogus
The value 24 was NOT found after 3 comparisons
```