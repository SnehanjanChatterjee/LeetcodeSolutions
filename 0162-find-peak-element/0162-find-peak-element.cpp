class Solution {
private:
    // https://www.youtube.com/watch?v=cXxmbemS6XM&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=10
    int striverSoln(vector<int>& nums, int n) {
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0; // 1st element is peak
        if (nums[n - 1] > nums[n - 2]) return n - 1; // last element is peak
        
        int low = 1, high = n - 2, mid;
        
        while (low <= high) {
            mid = low + ((high - low) / 2);
            
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
            
            // mid is part of increasing curve. So peak will definitely be on the right of mid. Hence, eliminate left part
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