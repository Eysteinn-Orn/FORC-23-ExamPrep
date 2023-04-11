#include <iostream>
#include <vector>
#include <fstream>
#include "result.h"

using namespace std;

vector<Result> read_results_from_file(string filename) {
    ifstream file(filename);

    vector<Result> results;

    while(!(file.eof() || file.peek() == EOF)) {
        string analyst;
        int count;
        double amount;
        bool confirmed;

        file >> analyst
             >> count
             >> amount
             >> confirmed;

        Result result(
            analyst,
            count,
            amount,
            confirmed
        );

        results.push_back(result);
    }

    file.close();

    return results;
}


int main(){
    auto results = read_results_from_file("result_test_file.txt");
    for(auto result : results){
        cout << result << endl;
    }
    return 0;
}