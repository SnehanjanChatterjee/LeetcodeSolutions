class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();
        int ans = 0;
        
        for(int c=0; c<cols; c++) {
            for(int r=1; r<rows; r++) {
                if(strs[r][c] < strs[r-1][c]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};