#include <iostream>
#include <fstream>
#include "player.h"
#include <vector>

//TODO: Implement read_players_from_file

using namespace std;

vector<Player> read_players_from_file(string filename) {
    ifstream file(filename);
    
    vector<Player> players;
    while (!file.eof()){
        string name;
        int number;
        double result;
        file >> name >> number >> result;
        Player player = Player(name, number, result);
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