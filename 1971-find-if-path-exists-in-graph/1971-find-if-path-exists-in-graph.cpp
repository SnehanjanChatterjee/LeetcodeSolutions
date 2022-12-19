class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n+1];
        vector<int> visited(n+1, 0);
        
        for(vector<int> &x: edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        return dfs(source, destination, visited, adj);
    }
    
    bool dfs(int node, int destination, vector<int> &visited, vector<int> adj[]) {
        if(node == destination) return true;
        visited[node] = 1; 
        for(int it: adj[node]) {
            if(!visited[it]) {
                if(dfs(it, destination, visited, adj)) return true;
            }
        }
        return false;
    }

};