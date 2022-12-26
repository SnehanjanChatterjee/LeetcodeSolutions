class Solution {
private:
    bool check(int ind, vector<int>& nums) {
        
        if(ind >= (nums.size() - 1)) return true;
        if(nums[ind] == 0) return false;
        
        for(int i=nums[ind]; i>=1; i--) {
            if(nums[ind] == 0) return false;
            if(check(ind + i, nums)) return true;
        }
        
        return false;
    }
    
    bool soln2(vector<int>& nums) {
        int maxReachableInd = 0, n = nums.size();
        
        for(int i=0; i<n && maxReachableInd<n && i<=maxReachableInd; i++) {
            maxReachableInd = max(maxReachableInd, i + nums[i]);
        }
        
        return (maxReachableInd >= (n - 1));
    }
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1) return true;
        
        // return check(0, nums);
        
        return soln2(nums);
    }
};