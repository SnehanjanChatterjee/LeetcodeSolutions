class Solution {
private:
    int striverSoln(vector<int>& nums, int n) {
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0; // 1st element is peak
        if (nums[n - 1] > nums[n - 2]) return n - 1; // last element is peak
        
        int low = 1, high = n - 2, mid;
        
        while (low <= high) {
            mid = low + ((high - low) / 2);
            
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
            
            if (nums[mid] > nums[mid - 1]) low = mid + 1;
            else high = mid - 1;
        }
        
        return -1;
    }
public:
    int findPeakElement(vector<int>& nums) {
        return striverSoln(nums, nums.size());
    }
};