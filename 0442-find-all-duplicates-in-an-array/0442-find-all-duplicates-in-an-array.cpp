class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int, int> mp;
        
        for(int &x: nums) mp[x]++;
        
        vector<int> ans;
        
        for(auto &x: mp) {
            if(x.second > 1) {
                ans.push_back(x.first);
            }
        }
        
        return ans;
    }
};