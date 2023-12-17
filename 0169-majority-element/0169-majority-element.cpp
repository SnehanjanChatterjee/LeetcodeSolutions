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
        nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
        return nums[nums.size()/2];
    }
};