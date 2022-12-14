class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // vector<int> dp(n+1, -1);
        // return TopDownDP(n-1, nums, dp);
        
        return SpaceOptimized(1, n-1, nums);
    }
    
    int SpaceOptimized(int start, int end, vector<int>& nums) {
        int prev2 = 0;
        int prev = nums[start-1];
        int current = 0;
        
        for(int i=start; i<=end; i++) {
            // If i==1, (i-2)th index goes out of bound.
            // So take the ith value, but go to (i-2)th index only if possible
            int takeCurrentHouse = nums[i];
            if(i-2 >= 0) takeCurrentHouse += prev2;
            
            int notTakeCurrentHouse = 0 + prev;
            
            current = max(takeCurrentHouse, notTakeCurrentHouse);
            
            prev2 = prev;
            prev = current;
        }
        
        return prev;
    }
    
    int TopDownDP(int n, vector<int>& nums, vector<int>& dp) {
        if(n == 0) return nums[n];
        if(n < 0) return 0;
        
        if(dp[n] != -1) return dp[n];
        
        int takeCurrentHouse = nums[n] + TopDownDP(n-2, nums, dp);
        int notTakeCurrentHouse = 0 + TopDownDP(n-1, nums, dp);
        
        return dp[n] = max(takeCurrentHouse, notTakeCurrentHouse);
    }
};