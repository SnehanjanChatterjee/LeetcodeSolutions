class Solution {
public:
    // Here we can use the XOR property A ^ A = 0
    // From this we know if we do XOR of any 2 duplicate numbers, 
    // result will be 0. But the current array doesn't have any duplicate number. So we can do:
    // Here the duplicate numbers will cancel out.
    // Remaining numbers will be 0 & the missing number, 
    // XOR of which will again give the result as the missing number due to following XOR property A ^ 0 = A
    int missingNumber(vector<int>& nums) {
        long missingNum = 0;
        int n = nums.size();
        for(int i=0; i<=n; i++) {
            missingNum = missingNum ^ i;
        }
        for(int i=0; i<n; i++) {
            missingNum = missingNum ^ nums[i];
        }
        return missingNum;
    }
};