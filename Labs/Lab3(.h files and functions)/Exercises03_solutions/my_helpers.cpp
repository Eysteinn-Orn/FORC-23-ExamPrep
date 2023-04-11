#include <iostream>

#include "my_helpers.h"

double circumference(double radius){
    return radius * 2 * 3.14159;
}


bool linear_search(char array[], int value, int array_length, int &index, int &comparisons){
        comparisons = 0;
        while(array[comparisons++] != value){
            if(comparisons == array_length){
                return false;
            }
        }
        index = comparisons - 1;
        return true;
}


bool bin_search_rec(char array[], int value, int left, int right, int &index, int &comparisons){
    std::cout << "recurring" << std::endl;
    if(left == right){
        std::cout << "bogus" << std::endl;
        return false;
    }
    comparisons++;
    int mid = (left + right) / 2;
    if(value == array[mid]){
        std::cout << "Excellent!" << std::endl;
        index = mid;
        return true;
    }
    else if(value < array[mid]){
        if(mid == left){
            std::cout << "bogus" << std::endl;
            return false;
        }
        else{
            std::cout << "going left " << left << " " << mid << " " << right << std::endl;
            return bin_search_rec(array, value, left, mid - 1, index, comparisons);
        }
    }
    else{ // value > array[mid]
            std::cout << "going right " << left << " " << mid << " " << right << std::endl;
        return bin_search_rec(array, value, mid + 1, right, index, comparisons);
    }
}

bool binary_search(char array[], int value, int array_length, int &index, int &comparisons){
    comparisons = 0;
    return bin_search_rec(array, value, 0, array_length - 1, index, comparisons);
}