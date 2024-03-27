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
            
            cnt += (right - left + 1);
            
            right++;
        }
        
        return cnt;
    }
};