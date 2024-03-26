class Solution {
private:
    int mySolution(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for(int i=1; i<1000000; i++) {
            if(!binary_search(nums.begin(), nums.end(), i)) {
                return i;
            }
        }
        
        return 1;
    }
    
    // https://leetcode.com/problems/first-missing-positive/discuss/17071/My-short-c%2B%2B-solution-O(1)-space-and-O(n)-time
    // Put each number in its right place. For example: When we find 5, then swap it with A[4].
    // At last, the first place where its number is not right, return the place + 1.
    // For negative numbers, it will get swapped to a wrong position.
    int optimizedSolution(vector<int>& nums) {
        int n = nums.size(); 
        for (int i = 0; i < n; i++)
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        
        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;
        return n + 1;
    }
public:
    int firstMissingPositive(vector<int>& nums) {
        // return mySolution(nums);
        
        return optimizedSolution(nums);
    }
};