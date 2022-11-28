class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // {playerId, lostCount}
        unordered_map<int, int> ump;
        int winner, loser;
        
        for(vector<int>& v: matches) {
            winner = v[0], loser = v[1];
            // If a winner doesn't exist in map (i.e hasn't played a match yet), this player's lost count till now would be 0 as this is his 1st watch and he won.
            // So this would insert him into the map with lostCount = 0. So if he lose in the future we would just increase his lostCount
            if(ump.find(winner) == ump.end()) {
                ump[winner] = 0;
            }
            // Loser exists in map or not doesn't matter, increase this player's lost count
            ump[loser]++;
        }
        
        vector<vector<int>> ans (2);
        for(auto x: ump) {
            if(x.second == 0) ans[0].push_back(x.first);
            if(x.second == 1) ans[1].push_back(x.first);
        }
        
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        
        return ans;
    }
};