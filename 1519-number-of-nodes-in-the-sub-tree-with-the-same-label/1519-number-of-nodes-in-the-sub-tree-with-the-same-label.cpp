class Solution {
public:
    // https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/discuss/743220/C%2B%2B-DFS-%2B-DP-or-Vector-Counter-Implementation-or-O(n)
    void dfs (int node, int par, vector<vector<int>> &g, vector<vector<int>> &dp, vector<int> &ans, string &labels) {
        dp[node][labels[node]-'a']++;
        for (auto &child: g[node]) {
            if (child != par) {
                dfs(child, node, g, dp, ans, labels);
                for (int i=0; i<27; i++) {
                    dp[node][i] += dp[child][i];
                }
            }
        }
        ans[node] = dp[node][labels[node]-'a'];
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> g(n);
        for (int i=0; i<edges.size(); i++) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector <vector<int>> dp(n, vector<int>(27, 0));
        vector<int> ans(n);
        dfs(0, -1, g, dp, ans, labels);
        return ans;
    }
};