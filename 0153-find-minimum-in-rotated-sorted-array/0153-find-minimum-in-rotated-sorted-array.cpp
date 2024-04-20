class Solution {
private:
    // https://www.youtube.com/watch?v=nhEMDKMB44g&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=7
    int striverSoln(vector<int>& nums, int n) {
        int low = 0;
        int high = n-1;
        int mid;
        int ans = INT_MAX;
        
        while (low <= high) {
            mid = low + ((high - low) / 2);
            
            // Left half of mid is sorted
            if (nums[low] <= nums[mid]) {
                // Since left half is sorted,
                // we can directly check the first element of left half (i.e nums[left]) if it's the minimum value
                // & eliminate 1st half (we don't need to go into the 1st half as in a sorted space 1st element can only be minimum)
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            // Right half of mid is sorted
            else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        
        return ans;
    }
public:
    int findMin(vector<int>& nums) {
        return striverSoln(nums, nums.size());
    }
};