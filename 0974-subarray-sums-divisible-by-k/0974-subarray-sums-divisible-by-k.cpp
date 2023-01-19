class Solution {
public:
    // https://leetcode.com/problems/subarray-sums-divisible-by-k/discuss/3070599/ Day-19-oror-Explanation-with-Diagram-Prefix-Sum-and-HashMap-oror-O(N)-Time-and-O(N)-Space
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> output(k, 0);
        // prefixModSum is used to store sum of all prefix mods
        int prefixModSum = 0;
        int res = 0;
        output[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            // (nums[i] % k + k) is used to avoid nagative remainder
            prefixModSum = (prefixModSum + nums[i] % k + k) % k;
            // If in test case, only positive number given like [5,0,5,3] then
            // prefixModSum = prefixModSum + nums[i] % k;
            // Add the count of subarrays that have the same remainder
            res = res + output[prefixModSum];
            output[prefixModSum]++;
        }
        return res;
    }
};