class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        vector<vector<int>> ans;
        dfs(0, graph.size()-1, path, ans, graph);
        return ans;
    }
    
    void dfs(int node, int dest, vector<int> &path, vector<vector<int>> &ans, vector<vector<int>>& adj) {
        path.push_back(node);
        
        if(node == dest) {
            ans.push_back(path);
        }
        
        for(int it: adj[node]) {
            dfs(it, dest, path, ans, adj);
        }
        path.pop_back();
    }
};