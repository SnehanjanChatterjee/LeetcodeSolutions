class Solution {
private:
    // Worst case TC -> O(N) if array is fully rotated and element doesn't exist in array
    int mySolution(vector<int>& nums, int target, int n) {
        int index = 0;
        
        // Serch till pivot. If target lies before that we will get answer
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == target) return i;
            else if (nums[i] > nums[i + 1]) {
                index = i + 1;
                break;
            }
        }
        
        // Do binary search for array b/w pivot and end of array
        int low = index;
        int high = n-1;
        int mid;
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (nums[mid] == target) return mid;
            else if (nums[mid] <= target) low = mid + 1;
            else high = mid - 1;
        }
        
        return -1;
    }
    
    // https://www.youtube.com/watch?v=5qGrJbHhqFs&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=5
    int striverSoln(vector<int>& nums, int target, int n) {
        int low = 0;
        int high = n-1;
        int mid;
        
        while (low <= high) {
            mid = low + ((high - low) / 2);
            
            if(nums[mid] == target) return mid;
            
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
        
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        // return mySoln(nums, target, n);
        
        return striverSoln(nums, target, n);
    }
};