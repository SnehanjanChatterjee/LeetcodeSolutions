class Solution {
private:
    int countNums(vector<int>& nums, int capacity) {
        int curCapacity = 0, studentCnt = 1;
        
        for(int x: nums) {
            if (x + curCapacity <= capacity) curCapacity += x;
            else curCapacity = x, studentCnt++;
        }
        
        return studentCnt;
    }
    int binarySearch(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            
            if(countNums(nums, mid) <= k) high = mid - 1;
            else low = mid + 1;
        }
        
        return low;
    }
public:
    // Variety of Allocate Books problem
    // 1. https://www.youtube.com/watch?v=Z0hwjftStI4&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=19
    // 2. https://www.youtube.com/watch?v=thUd_WJn6wk&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=20
    int splitArray(vector<int>& nums, int k) {
        return binarySearch(nums, k);
    }
};