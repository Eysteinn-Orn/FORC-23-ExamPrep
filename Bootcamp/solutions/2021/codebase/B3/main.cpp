#include <iostream>
#include <vector>
#include <fstream>
#include "player.h"

using namespace std;

vector<Player> read_players_from_file(
    string filename
) {

    vector<Player> players;

    ifstream file(filename);

    while(!(file.eof() || file.peek() == EOF)) {
        string name;
        int number;
        double result;

        file >> name
             >> number
             >> result;
        
        Player player(
            name, 
            number,
            result
        );

        players.push_back(player);
    }

    file.close();

    return players;
}


int main(){
    auto players = read_players_from_file("player_test_file.txt");
    for(auto player : players){
        cout << player << endl;
    }
    return 0;
}