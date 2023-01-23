class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1);
        vector<int> adj[n+1];
        
        for(vector<int> &x: trust) {
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
        
        int count = 0;
        int ans;
        // Our reqd. node should have
        // 1) no outgoing edge
        // 2) incoming edges from all other nodes (i.e indegree = n-1)
        for(int i=0; i<indegree.size(); i++) {
            if(indegree[i] == n-1) {
                count++;
                ans = i;
            } 
        }
        
        // Node node exists with indegree = n-1
        if(count == 0) return -1;
        
        // Node with indegree = n-1 should not have any outgoing edge
        // i.e in adj list vector of this index should be empty
        return adj[ans].size() == 0 ? ans : -1;
    }
};