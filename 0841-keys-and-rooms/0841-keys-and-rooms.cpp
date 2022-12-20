class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> adj[n];
        
        for(int u=0; u<n; u++) {
            for(int v=0; v < rooms[u].size(); v++) {
                adj[u].push_back(rooms[u][v]);
            }
        }
        
        queue<int> q;
        vector<int> vis(n, -1);
        
        q.push(0);
        vis[0] = 1;
        int visited = 1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it: adj[node]) {
                if(vis[it] == -1) {
                    vis[it] = 1;
                    q.push(it);
                    visited++;
                }
            }
        }
        
        return visited == n;
    }
};