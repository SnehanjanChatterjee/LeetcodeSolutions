class Solution {
public:
    // Expl: https://www.youtube.com/watch?v=xvNwoz-ufXA&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=17
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        ump[0] = 1;
        int prefixSum = 0, cnt = 0, remove = 0;
        
        for (int &x: nums) {
            prefixSum += x;
            remove = prefixSum - k;
            cnt += ump[remove];
            ump[prefixSum]++;
        }
        
        return cnt;
    }
};