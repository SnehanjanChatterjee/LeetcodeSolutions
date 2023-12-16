class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int k = n - 1;
        
        // At any time either the leftmost or rightmost no's square will be the greater no
        // So put this no in the end of new array
        for(int i = 0, j = n - 1; i <= j;) {
            if(abs(nums[i]) > abs(nums[j])) {
                ans[k--] = pow(nums[i++], 2);
            } else {
                ans[k--] = pow(nums[j--], 2);
            }
        }
        return ans;
    }
};