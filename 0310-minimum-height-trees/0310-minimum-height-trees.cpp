class Solution {
public:
    // https://leetcode.com/problems/minimum-height-trees/discuss/1630778/C%2B%2B-Simple-Solution-or-Topological-Sort-or-W-Explanation
    
    // There can be atmost 2 trees with minimum height
    // For the graph with odd no. of nodes, only the node at the middle of the graph when made the root, will give a minimum height tree.
    // For the graph with even no. of nodes, both the middle nodes when made the root give a minimum height tree.
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0), ans; //vector<int> indegree keeps count of the number of nodes approaching a node
        
        for(auto &e : edges){   //Creating an adjacency matrix for the given graph
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indegree[i]==1) q.push(i), indegree[i]--; //add all the leaf nodes to the queue
        } 
        
        while(!q.empty()) {
            int s = q.size();
            ans.clear();
            while(s--) {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for(auto it : adj[node]){ //For each node, attached to the leaf niodes, we decrement the indegree i.e remove the leaf nodes connected to them. We keep on doing this until we reach the middle nodes.
                    indegree[it]--;
                    if(indegree[it] == 1) q.push(it);   
                }
            }
        }
        
        if(n == 1) return {0}; //If there is only 1 node in the graph, the min height is 0, with root being '0'
        return ans;
        
    }
};