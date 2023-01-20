class Solution {
private:
    void recur(int ind, int &n, vector<int>& nums, vector<int>& store, set<vector<int>>& ans) {
        if(ind == n) {
            if(store.size() >= 2) ans.insert(store);
            return;
        }

        if(!store.size() || nums[ind] >= store.back()) {
            store.push_back(nums[ind]);
            recur(ind+1, n, nums, store, ans);
            store.pop_back();
        }
        recur(ind+1, n, nums, store, ans);
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> store;
        set<vector<int>> ans;
        int n = nums.size();
        recur(0, n, nums, store, ans);
        return vector(ans.begin(), ans.end());
        
    }
};