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
        
        if (parU != parV) {
            parent[max(parU, parV)] = min(parU, parV);
        }
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        makeSet(27);
        
        for(int i=0; i<s1.size(); i++) {
            Union((s1[i] - 'a'), (s2[i] - 'a'));
        }
        
        string ans = "";
        for(char ch: baseStr) {
            int par = findParent((ch - 'a'));
            ans += (par + 'a');
        }
        
        return ans;
    }
};