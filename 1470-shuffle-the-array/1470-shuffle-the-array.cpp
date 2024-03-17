class Solution {
public:
    // Approach 1: https://www.youtube.com/watch?v=7HZmP8r1FBE (Using formula - Complex)
    // Approach 2: (Bit Manipulation - Complex)
    // Approach 3: https://leetcode.com/problems/shuffle-the-array/discuss/1314638/JAVA-C%2B%2B-%3A-Simple-or-O(1)-Space-In-Place-or-100-Faster-or-Efficient-or-Explained (Best - Also covers Approach 2)
    vector<int> shuffle(vector<int>& nums, int n) {
        int len = nums.size();
        
         // NOTE: Here, we will take 1024 because of the given constraints 1 <= nums[i] <= 10^3 i.e. the largest number in the array will be 1000
        
		// to store the pair of numbers in right half of the original array
        for(int i = n; i < nums.size(); i++) {
            nums[i] = (nums[i] * 1024) + nums[i - n];
        }
        
		// to retrive values from the pair of numbers and placing those retrieved value at their desired position
        for(int i = n, index = 0; i < nums.size(); i++, index += 2) {
            nums[index] = nums[i] % 1024;
            nums[index + 1] = nums[i] / 1024;
        }
        
        return nums;
    }
};