class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // {playerId, lostCount}
        unordered_map<int, int> ump;
        
        for(vector<int>& v: matches) {
            int winner = v[0];
            int loser = v[1];
            if(ump.find(winner) == ump.end()) {
                ump[winner] = 0;
            }
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