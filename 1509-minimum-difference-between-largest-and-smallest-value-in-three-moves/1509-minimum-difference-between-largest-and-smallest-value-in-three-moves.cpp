class Solution {
private:
    // https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/discuss/5406010/3-Solutions-Tutorial-O(n)-Included-Minimum-Difference-Between-Largest-and-Smallest-Value
    int leetcodeDiscussionSoln(vector<int>& nums) {
        if(nums.size() <= 4) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ans = nums.back() - nums[0];
        for(int i = 0; i <= 3; i++) {
            ans = min(ans, nums[nums.size() - (3 - i) - 1] - nums[i]);
        }
        return ans;
    }
    
    // https://www.youtube.com/watch?v=HQix60wTKPc
    int frazSoln(vector<int>& nums) {
        int n = nums.size();
        
        if(n <= 4) return 0;
        
        sort(nums.begin(), nums.end());
        
        // Here we have to reduce the difference b/w the largest and smallest
        
        int option1 = nums[n-4] - nums[0]; // Make last 3 elements same as 1st element. So now max element is (n-4)th element
        int option2 = nums[n-3] - nums[1]; // Make 1st 2 & last 2 elements same. So now max element is (n-3)th element
        int option3 = nums[n-2] - nums[2]; // Make 1st 3 & last elements same. So now max element is (n-2)th element
        int option4 = nums[n-1] - nums[3]; // Make 1st 3 elements same as last element. So now max element is (n-1)th element
        
        return min(option1, min(option2, min(option3, option4)));
    }
public:
    int minDifference(vector<int>& nums) {
        // return leetcodeDiscussionSoln(nums);
        
        return frazSoln(nums);
    }
};