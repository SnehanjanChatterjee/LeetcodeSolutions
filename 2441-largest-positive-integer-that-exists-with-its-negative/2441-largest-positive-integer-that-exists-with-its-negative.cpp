class Solution {
public:
    int findMaxK(vector<int>& nums) {
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
};