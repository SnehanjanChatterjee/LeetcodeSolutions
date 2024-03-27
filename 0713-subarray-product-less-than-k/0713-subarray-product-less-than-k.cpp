class Solution {
public:
    // Reference:
    // https://www.youtube.com/watch?v=SxtxCSfSGlo
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        
        int left = 0, right = 0, n = nums.size(), cnt = 0, product = 1;
        
        while(right < n) {
            product *= nums[right];
            
            while (left <= right && product >= k) {
                product /= nums[left];
                left++;
            }
            
            // https://leetcode.com/problems/subarray-product-less-than-k/discuss/108861/JavaC++-Clean-Code-with-Explanation/288776
            cnt += (right - left + 1);
            
            right++;
        }
        
        return cnt;
    }
};