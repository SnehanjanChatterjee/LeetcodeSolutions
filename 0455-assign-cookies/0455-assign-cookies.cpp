class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int g_size = g.size(), s_size = s.size();
        int g_end = g_size - 1, s_end = s_size - 1;
        int ans = 0;
        
        while(s_end >= 0 && g_end >= 0) {
            if (s[s_end] >= g[g_end]) {
                ans++;
                s_end--;
                g_end--;
            } else {
                g_end--;
            }
        }
        
        return ans;
    }
};