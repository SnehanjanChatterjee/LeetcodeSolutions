class Solution {
private:
    vector<int> rank;
    vector<int> parent;
    void makeSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
    }
    int findParent(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    void Union(int u, int v) {
        int parU = findParent(u);
        int parV = findParent(v);
        
        if(rank[parU] < rank[parV]) parent[parU] = parV;
        else if(rank[parV] < rank[parU]) parent[parV] = parU;
        else {
            parent[parV] = parU;
            rank[parU]++;
        }
    }
public:
    bool equationsPossible(vector<string>& equations) {
        makeSet(27);
        
        // We will store variables in same component if they are equal.
        for(string &s: equations) {
            if(s[1] == '=') Union(s[0] - 'a', s[3] - 'a');
        }
        
        // we will check non-equality equtions, if both variables in any of those equation are in same component, we return false.
        for(string &s: equations) {
            if(s[1] == '!') {
                // If parent of both nodes are same, they are in same component
                if(findParent(s[0] - 'a') == findParent(s[3] - 'a')) return false;
            }
        }
        
        return true;
    }
};