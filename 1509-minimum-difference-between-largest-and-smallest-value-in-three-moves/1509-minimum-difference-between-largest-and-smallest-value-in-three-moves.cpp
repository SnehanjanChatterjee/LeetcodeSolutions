class Solution {
public:
    // https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/discuss/5406010/3-Solutions-Tutorial-O(n)-Included-Minimum-Difference-Between-Largest-and-Smallest-Value
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ans = nums.back() - nums[0];
        for(int i = 0; i <= 3; i++) {
            ans = min(ans, nums[nums.size() - (3 - i) - 1] - nums[i]);
        }
        return ans;
    }
};