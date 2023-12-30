class Solution {
private:
    int hashingSoln(vector<int>& nums) {
        // Hashing Technique
        unordered_map<int, int> mp;
        int majorityCount = floor(nums.size() / 2);
        for(int &x: nums) {
            mp[x]++;
            if(mp[x] > majorityCount) {
                return x;
            }
        }
        return nums[0];
    }
    
    // Boyer-Moore Voting Algorithm
    // https://www.youtube.com/watch?v=nP_ns3uSh80&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=7
    int MooresVotingAlgo(vector<int>& nums) {
        int count = 0;
        int majorityElement = 0;
        int n = nums.size();
        
        for(int &x: nums) {
            if(count == 0) {
                majorityElement = x;
                count = 1;
            }
            else if(majorityElement == x)
                count++;
            else
                count--;
        }
        
        // Check if it's actually majority ele (Optional for this prob. as here it's mentioned majority ele does exist)
        count = 0;
        for(int &x: nums) {
            if(x == majorityElement) count++;
        }
        int majorityCnt = floor(n/2);

        return (count > majorityCnt) ? majorityElement : -1;
    }
    
    // Median of array also O(N) complexity same as Boyer-Moore 
    // Explanation: https://leetcode.com/problems/majority-element/discuss/1427775/2-line-easy-and-clean-C%2B%2B-solution-(explained)
    int calcMedian(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
        return nums[nums.size()/2];
    }
public:
    int majorityElement(vector<int>& nums) {
        // return hashingSoln(nums);
        
        return MooresVotingAlgo(nums);
        
        // return calcMedian(nums);
    }
};