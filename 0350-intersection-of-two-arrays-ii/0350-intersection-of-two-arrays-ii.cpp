class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() < nums2.size()) return intersect(nums2, nums1);
        
        map<int, int> freq;
        
        for(auto x: nums1) freq[x]++;
        
        vector<int> ans;
        for(auto x: nums2) {
            if(freq[x] > 0) {
                freq[x]--;
                ans.push_back(x);
            }
        }
        return ans;
    }
};