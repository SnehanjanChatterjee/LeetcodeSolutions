class Solution {
private:
    // Kadane's Algorithm
    int kadanesMaxSubArraySum(int &n, vector<int>& nums) {
        int maxSum = INT_MIN, currSum = 0;
        for (int i=0; i<n; i++) {
            currSum += nums[i];
            if (currSum > maxSum) maxSum = currSum;
            if (currSum < 0) currSum = 0;
        }
        return maxSum;
    }
public:
    // https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/633401/Kadane-Algorithm-Trick-beats-100-Java-Explained
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        
        // 1. For non-circular array
        // Find the maximum subarray sum using Kadane Algorithm. This is maximum sum for non circular array.
        int nonCircularSum = kadanesMaxSubArraySum(n, nums);
        
        // 2. For circular array
        
        int totalSum = 0;
        // Find the total sum of array
        for(int i=0; i<n; i++) {
            totalSum += nums[i];
            nums[i] = -nums[i]; // The trick here is that to find the minimum subarray sum, we invert the sign of all the numbers in original subarray, and find the maximum subarray sum using Kadane algorithm. Then add it with the total sum. (which is similar to [total - minimum subarray sum ])
        }
              
        // The max subarray sum for circular array = Total Sum - Minimum subarray Sum
        int circularSum = totalSum + kadanesMaxSubArraySum(n, nums);
        
        if(circularSum == 0) return nonCircularSum;
        return max(circularSum, nonCircularSum);
    }
};