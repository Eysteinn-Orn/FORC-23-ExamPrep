#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <string>
#include <functional>
#include <fstream>

using namespace std;

/* change return value and/or add parameters*/
vector<int> do_operation_on_entire_list(
    vector<int> &list1, 
    vector<int> &list2,
    std::function<int(int, int)> f
){
    vector<int> result;
    for(int i = 0; i < min(list1.size(), list2.size()); i++) {
        result.push_back(f(list1[i], list2[i]));
    }

    return result;
}

int add_numbers(int number1, int number2){
    return number1 + number2;
}

vector<int> read_list(string filename){
    vector<int> numbers;

    ifstream file(filename);
    while(!file.eof()){
        int n;
        file >> n;
        numbers.push_back(n);
    }

    return numbers;
}

int main(){
    vector<int> v1 = read_list("numbers01.txt");
    vector<int> v2 = read_list("numbers02.txt");

    char operation;
    bool valid = false;
    std::function<int(int, int)> f;

    while(!valid) {
        std::cout << "Select one of the following operations:"<< endl;
        std::cout << "[a]dd / [m]ult / [s]ub / [l]ower / [h]igher" << endl;
        std::cout << "Operation: ";
        cin >> operation;

        valid = true;

        switch(operation) {
            case 'a': {
                f = [](int a, int b){ return a + b;};
                break;
            }
            case 'm': {
                f = [](int a, int b){return a * b;};
                break;
            }
            case 's': {
                f = [](int a, int b){return a - b;};
                break;
            }
            case 'l': {
                f = [](int a, int b){return min(a, b);};
                break;
            }
            case 'h': {
                f = [](int a, int b){return max(a, b);};
                break;
            }
            default: {
                valid = false;
                std::cout << "Invalid operation.";
                break;
            }
        }
    }

    vector<int> result = do_operation_on_entire_list(v1, v2, f);

    std::cout << "Vector1" << endl;
    for(int n: v1){
        cout << n << " ";
    }
    std::cout << "\n" << endl;

    std::cout << "Vector2" << endl;
    for(int n: v2){
        cout << n << " ";
    }
    std::cout << "\n" << endl;

    std::cout << "Result" << endl;
    for(int n: result){
        cout << n << " ";
    }
    std::cout << endl;



}