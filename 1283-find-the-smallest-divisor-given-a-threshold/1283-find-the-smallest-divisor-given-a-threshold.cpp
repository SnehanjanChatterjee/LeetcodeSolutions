class Solution {
private:
    int totalSum(vector<int>& nums, int divisor) {
        int sum = 0;
        
        for(int &x: nums) sum += (ceil)((double)x / (double)divisor); 
        
        return sum;
    }
    
    // TC -> O(N * (max of array))
    // SC -> O(1)
    int striver_BruteForce(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        
        for (int i = low; i <= high; i++) {
            if (totalSum(nums, i) <= threshold) return i;
        }
        return -1;
    }
    
    // TC -> O(N * log(max of array))
    // SC -> O(1)
    int striver_Optimal(vector<int>& nums, int threshold) {
        // Min sum possible is when all elementsd are divided by max element. In that case sum = size of array
        // So if size of array is > threshold ans is not possible
        if (nums.size() > threshold) return -1;
        
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (totalSum(nums, mid) <= threshold) high = mid - 1;
            else low = mid + 1;
        }
        
        return low;
    }
public:
    // https://www.youtube.com/watch?v=UvBKTVaG6U8&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=15
    int smallestDivisor(vector<int>& nums, int threshold) {
        // return striver_BruteForce(nums, threshold);
        return striver_Optimal(nums, threshold);
    }
};