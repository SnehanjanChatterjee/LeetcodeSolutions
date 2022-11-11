class Solution {
private:
    int soln1(vector<int>& nums) {
        int n = nums.size();
        for(auto i = nums.begin()+1; i != nums.end(); ++i) {
            if(*i == *(i-1)) {
                nums.erase(i);
                i--;
            }
        }
        return nums.size();
    }
    int soln2(vector<int>& nums) {
        // Two Pointer
        int i = 0;
        int j = 1;
        while(j < nums.size()) {
            if(nums[j] != nums[i]) {
                nums[++i] = nums[j++];
            }
            else
                j++;
        }
        return i + 1;
    }
public:
    int removeDuplicates(vector<int>& nums) {
        // return soln1(nums);
        
        return soln2(nums);
    }
};