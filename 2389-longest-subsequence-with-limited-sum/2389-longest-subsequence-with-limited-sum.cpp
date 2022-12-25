class Solution {
private:
    vector<int> soln1(vector<int>& nums, vector<int>& queries) {
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
                    // sum = 0;
                    // c = 0;
                    break;
                }
                //maxC = max(maxC, c);
            }
            // ans.push_back(maxC);
            ans.push_back(c);
            itr++;
        }
        
        return ans;
    }
    
    // https://leetcode.com/problems/longest-subsequence-with-limited-sum/discuss/2493409/JavaC%2B%2BPython-Binary-Search
    // Explanation:
    // 1. Sort input A, since we care the sum and doesn't care the order.
    // 2. Calculate the prefix sum of A, since we want to know the accumulate sum.
    // 3. Binary seach each query q in query, and the index is the result.
    // 4. return result res.
    vector<int> soln2(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i - 1];
        }
        for (int& q: queries) {
            res.push_back(upper_bound(nums.begin(), nums.end(), q) - nums.begin());
        }
        return res;
    }
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        // return soln1(nums, queries);
        
        return soln2(nums, queries);
    }
};