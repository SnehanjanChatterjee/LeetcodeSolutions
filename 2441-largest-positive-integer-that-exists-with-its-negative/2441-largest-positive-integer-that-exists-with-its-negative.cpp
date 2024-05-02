class Solution {
private:
    int using2Pointer(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int low = 0, high = nums.size() - 1;
        
        while(low <= high)
        {
            if((nums[low] + nums[high]) == 0) return  nums[high];
            else if((nums[low] + nums[high]) < 0) low++;
            else high--;
        }
        
        return -1;
    }
    int usingSet(vector<int>& nums) {
        unordered_set<int> ust;
        int maxK = -1;
        
        for (int &x: nums) {
            if (ust.find(-1*x) != ust.end()) {
                maxK = max(maxK, abs(x));
            }
            ust.insert(x);
        }
        
        return maxK;
    }
public:
    int findMaxK(vector<int>& nums) {
        // return usingSet(nums);
        return using2Pointer(nums);
    }
};