class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int q = queries.size();
        int n = nums.size();
        vector<int> ans;
        int itr = 0;
        
        while(itr < q) {
            int k = queries[itr];
            int sum = 0, c = 0, maxC = INT_MIN;
            for(int i=0; i<n; i++) {
                if(sum + nums[i] <= k) {
                    sum += nums[i];
                    c++;
                }
                else {
                    sum = 0;
                    c = 0;
                }
                maxC = max(maxC, c);
            }
            ans.push_back(maxC);
            itr++;
        }
        
        return ans;
    }
};