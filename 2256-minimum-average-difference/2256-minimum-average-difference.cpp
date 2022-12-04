class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n, 0);
        vector<long long> suffixSum(n, 0);
        
        suffixSum[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--) {
            suffixSum[i] = nums[i] + suffixSum[i+1];
        }
        
        prefixSum[0] = nums[0];
        for(int i=1; i<n; i++) {
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }
        
        int ans = INT_MAX;
        long long minDiff = INT_MAX;
        for(int i=0; i<n; i++) {
            int firstHalfCount = i + 1;
            int secondHalfCount = n - i - 1;
            
            long long firstHalfAvg = prefixSum[i] / firstHalfCount;
            long long secondHalfAvg = secondHalfCount == 0 ? 0 : ((suffixSum[i] - nums[i]) / secondHalfCount);
            
            long long absDiff = abs(firstHalfAvg - secondHalfAvg);
            if(absDiff < minDiff) {
                minDiff = min(minDiff, absDiff);
                ans = i;
            }
        }
        
        return ans;
    }
};