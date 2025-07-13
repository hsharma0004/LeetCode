class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());

    int player = 0;
    int trainer = 0;
    int pairs = 0;
    while (player < players.size() && trainer < trainers.size()) {
 
        if (players[player] <= trainers[trainer]) {
            pairs++;    
            player++;         
            trainer++;        
        } else   trainer++;
    }
    return pairs;
    }
};