class Solution {
private:
    // 2 pointer with map
    vector<int> solution1(vector<int>& nums, int target) {
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
    
    // 2 Pointer with sorted array
    vector<int> solution2(vector<int>& nums, int target) {
        int n = nums.size(), i = 0, j = n - 1;
        vector<pair<int, int>> nums2;
        
        for(int i = 0; i < n; i++) {
            nums2.push_back({nums[i], i});
        }
        sort(nums2.begin(), nums2.end());
        
        while(i<j && i<n && j>=0) {
            if(nums2[i].first + nums2[j].first == target) return {nums2[i].second, nums2[j].second};
            else if(nums2[i].first + nums2[j].first < target) i++;
            else if(nums2[i].first + nums2[j].first > target) j--;
        }
        return {};
    }
    
    // Hashing
    vector<int> solution3(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> ump;
        
        for(int i=0; i<n; i++) {
            int remainder = target - nums[i];
            if(ump.find(remainder) != ump.end()) {
                return {i, ump[remainder]};
            }
            ump.insert({nums[i], i});
        }
        
        return {};
    }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // return solution1(nums, target);
        // return solution2(nums, target);
        return solution3(nums, target);
    }
};