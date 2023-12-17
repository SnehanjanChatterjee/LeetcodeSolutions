class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int posIndex = 0, negIndex = 1, n = nums.size();
        vector<int> ans(n);
        
        // We can see in resultant array, all positive numbers takes up the even indexes and neg nos odd indexes
        for(int i=0; i<n; i++) {
            if(nums[i] < 0) {
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
            else {
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
        }
        return ans;
    }
};