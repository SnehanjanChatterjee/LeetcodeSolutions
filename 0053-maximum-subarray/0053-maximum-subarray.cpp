class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        // DP Solution
//         int n = nums.size();
//         vector<int> dp(n);//dp[i] means the maximum subarray ending with A[i];
//         dp[0] = nums[0];
//         int maxElement = dp[0];
        
//         for(int i = 1; i < n; i++){
//             dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
//             maxElement = max(maxElement, dp[i]);
//         }
        
        // Const space soln, time -> O(N)
        // Kadane's Algorithm
        int sum = 0;
        int maxElement = nums[0];
        for(int x: nums) {
            sum += x;
            maxElement = max(maxElement, sum);
            if(sum < 0) {
                sum = 0;
            }
        }
        
        return maxElement;
    }
};