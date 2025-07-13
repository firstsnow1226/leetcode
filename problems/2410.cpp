class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        int ans = 0;
        int ptr = 0;
        for(auto x:trainers){
            if( ptr >= players.size() )
                break;
            if( players[ptr] <= x ){
                ans++;
                ptr++;
            }

        }
        return ans;
    }
};
