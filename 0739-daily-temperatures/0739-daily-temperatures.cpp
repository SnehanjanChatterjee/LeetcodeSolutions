class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // {value, index}
        stack<pair<int, int>> st;
        int n = temperatures.size();
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--) {
            int cur = temperatures[i];
            if(!st.empty()) {
                while(!st.empty() && st.top().first <= cur) st.pop();
                if(!st.empty()) {
                    auto itr = st.top();
                    int reqIndex = itr.second;
                    ans[i] = reqIndex - i;
                    
                }
            }
            st.push({cur, i});
        }
        
        return ans;
    }
};