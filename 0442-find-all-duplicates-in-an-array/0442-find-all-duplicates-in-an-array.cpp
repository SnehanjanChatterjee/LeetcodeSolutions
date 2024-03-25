class Solution {
private:
    vector<int> mySolution(vector<int>& nums) {
        unordered_map<int, int> ump;

        for(int &x: nums) ump[x]++;

        vector<int> ans;

        for(auto &x: ump) {
            if(x.second > 1) {
                ans.push_back(x.first);
            }
        }

        return ans;
    }
    
    // Ref: https://www.youtube.com/watch?v=aMsSF1Il3IY
    vector<int> optimizedSolution(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        // Since in the array there are elements from 1-n, (nums[i]-1) will always be a valid index.
        // So if there are duplicate numbers, (nums[i]-1) will point to same index
        // We can keep marking every (nums[i]-1)th value as negative so that if we get a negative number,
        // we would know someone with same value marked this num as negative
        for(int i = 0; i<n; i++) {
            int index = abs(nums[i]) - 1;
            if(nums[index] < 0) ans.push_back(abs(nums[i]));
            nums[index] = -(nums[index]);
        }
        
        return ans;
    }
public:
    // If we are said to return a container, that doesn't count as extra space
    vector<int> findDuplicates(vector<int>& nums) {
        // return mySolution(nums);
        
        return optimizedSolution(nums);
    }
};