class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        // Andrew's monotone chain method.
        sort(begin(trees), end(trees), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        // left to right
        const int n = size(trees);
        vector<vector<int>> ans;
        ans.reserve(n);
        for (int i = 0; i < n; ++i) {
            while (size(ans) > 1 && orientation(ans[size(ans) - 2], ans.back(), trees[i]) < 0) 
                ans.pop_back();
            ans.push_back(trees[i]);
        }
        // If all trees are along a line, size(ans) is n after left to right procedure.
        if (size(ans) == n) return ans;

        // right to left
        for (int i = n - 2; i >= 0; --i) {
            while (size(ans) > 1 && orientation(ans[size(ans) - 2], ans.back(), trees[i]) < 0) 
                ans.pop_back();
            ans.push_back(trees[i]);
        }
        ans.pop_back();
        return ans;
    }

    static int orientation(const vector<int>& a, const vector<int>& b, const vector<int>& c) {
        return (b[0] - a[0]) * (c[1] - b[1]) - (b[1] - a[1]) * (c[0] - b[0]);
    }
};