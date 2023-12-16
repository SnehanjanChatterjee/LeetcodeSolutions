class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> us;
        int rows = paths.size();
        string ans = "";

        for(int row = 0; row < rows; row++) {
            us.insert(paths[row][0]);
        }
        for(int row = 0; row < rows; row++) {
            if (us.insert(paths[row][1]).second) {
                ans = paths[row][1];
                break;
            }
        }
        return ans;
    }
};