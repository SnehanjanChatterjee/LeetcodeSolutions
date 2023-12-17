class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Hashing Technique
        // unordered_map<int, int> mp;
        // int majorityCount = floor(nums.size() / 2);
        // for(int &x: nums) {
        //     mp[x]++;
        //     if(mp[x] > majorityCount) {
        //         return x;
        //     }
        // }
        // return nums[0];
        
        // Boyer-Moore Voting Algorithm
        // https://www.youtube.com/watch?v=nP_ns3uSh80&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=7
//         int count = 0;
//         int majorityElement = 0;
        
//         for(int &x: nums) {
//             if(count == 0) {
//                 majorityElement = x;
//             }
//             if(majorityElement == x)
//                 count++;
//             else
//                 count--;
//         }
//         return majorityElement;
        
        // Median of array also O(N) complexity same as Boyer-Moore 
        // Explanation: https://leetcode.com/problems/majority-element/discuss/1427775/2-line-easy-and-clean-C%2B%2B-solution-(explained)
        nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
        return nums[nums.size()/2];
    }
};