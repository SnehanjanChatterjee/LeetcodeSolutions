class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multimap<int, int> mp;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            mp.insert({nums[i], i});
        }
        
        auto i = mp.begin();
        auto j = prev(mp.end());
        
        while (distance(i ,j) > 0)
        {
            if(i->first + j->first == target) return {i->second, j->second};
            else if(i->first + j->first > target) j--;
            else if(i->first + j->first < target) i++;
        }
        return {};
    }
};