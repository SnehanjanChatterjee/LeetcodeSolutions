class Solution {
private:
    // https://www.youtube.com/watch?v=w2G2W8l__pc&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=6
    bool striverSoln(vector<int>& nums, int target, int n) {
        int low = 0;
        int high = n-1;
        int mid;
        
        while (low <= high) {
            mid = low + ((high - low) / 2);
            
            if (nums[mid] == target) return true;
            
            // Only this line is added else same code as https://leetcode.com/problems/search-in-rotated-sorted-array/
            // Here we can have duplicates. So searching for sorted half might fail if low, mig, high all have same values
            // Eg. [3 (low), 1, 2, 3 (mid), 3, 3, 3 (high)]
            // For this reduce the search space and continue with binary search
            if (nums[mid] == nums[low] && nums[mid] == nums[high]) {
                low++;
                high--; 
                continue;
            }
            
            // Left half of mid is sorted
            if (nums[low] <= nums[mid]) {
                // target actually lies in this sorted half i.e b/w low and mid
                if(target >= nums[low] && target <= nums[mid]) high = mid - 1;
                else low = mid + 1;
            }
            // Right half of mid is sorted
            else {
                if(target >= nums[mid] && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }
        }
        
        return false;
    }
public:
    bool search(vector<int>& nums, int target) {
        return striverSoln(nums, target, nums.size());
    }
};