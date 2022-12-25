class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        vector<int> ans;
        
        for (int& x: nums) {
            auto itr = lower_bound(sortedNums.begin(), sortedNums.end(), x);
            // cout << *itr << endl;
            ans.push_back(itr - sortedNums.begin());
        }
        
        return ans;
    }
};