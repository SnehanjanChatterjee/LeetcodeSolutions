class Solution {
    // https://leetcode.com/problems/arithmetic-slices-ii-subsequence/discuss/1455315/C%2B%2B-Simple-and-Short-DP-Solution-With-Explanation
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector< unordered_map<long, long> > dp(nums.size());
        int res = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                long diff = (long)nums[i] - (long)nums[j];
                
                dp[i][diff]++;
                
                if (dp[j].find(diff) != dp[j].end()) {
                    dp[i][diff] += dp[j][diff];
                    res += dp[j][diff];
                }
            }
        }
        
        return res;
    }
};