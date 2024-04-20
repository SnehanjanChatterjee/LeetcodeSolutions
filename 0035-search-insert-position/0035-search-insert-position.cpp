class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1, mid = 0;
        int ans = n;
        
        // Finding lower bound
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        // If lower bound was not found in array, answer will be (last index of array + 1) i.e n.
        // So we initialise ans with n and in case of no answer ans will never get updated
        return ans;
    }
};