class Solution {
private:
    bool solution1(vector<int>& nums) {
        unordered_set<long> us(nums.begin(), nums.end());
        return us.size() != nums.size(); 
    }

    bool solution2(vector<int>& nums) {
        unordered_map<long, long> ump;
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            ump[nums[i]]++;
            if (ump[nums[i]] > 1) return true;
        }

        return false;
    }
public:
    bool containsDuplicate(vector<int>& nums) {
        // Solution 1
        // return solution1(nums);

        // Solution 2
        return solution2(nums);
    }
};