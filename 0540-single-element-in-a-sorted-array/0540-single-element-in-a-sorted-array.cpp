class Solution {
public:
    // https://www.youtube.com/watch?v=AZOmHuHadxQ&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=9
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1, mid;
        
        if (n == 1) return nums[0];
        
        while (low <= high) {
            mid = low + ((high - low) / 2);
            
            // Check if you are in 1st half of partition
            // [Partition is done where single element lies.
            // 1,1,|2,3,3,4,4,8,8. Partiton at 1st index before 2
            // So we have to move towards that single element]
            // If in 1st half of single ele, 1st instance of duplicate no is at -> even index, 2nd instance -> odd index
            // If in 2nd half of single ele, 1st instance of duplicate no is at -> odd index, 2nd instance -> even index
            // So checking if mid is even
            if(mid % 2 == 0) {
                // Since mid is even for this to be in 1st half of partition
                // Current no and its next no has to be same
                if (nums[mid] != nums[mid + 1]) high = mid - 1; // Shrinking the right half
                else low = mid + 1; // Shrinking the left half
            } else {
                // Checking whether we are in right half
                if (nums[mid] == nums[mid + 1]) high = mid - 1; // Shrinking the left half
                else low = mid + 1; // Shrinking the right half
            }
        }
        
        return nums[low];
    }
};