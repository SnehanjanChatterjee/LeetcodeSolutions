class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // {value, index}
        stack<pair<int, int>> st;
        int n = temperatures.size();
        vector<int> ans(n);
        
        for(int curInd = n - 1; curInd >= 0; curInd--) {
            int curTemp = temperatures[curInd];
            if(!st.empty()) {
                // Till we dont find a temp > current temp keep popping stack elements
                while(!st.empty() && st.top().first <= curTemp) {
                    st.pop();
                }
                
                // Check after popping all elements if stack still has any element
                // If it has that must a temp > current temp
                if(!st.empty()) {
                    int reqInd = st.top().second;
                    ans[curInd] = reqInd - curInd;
                }
            }
            st.push({curTemp, curInd});
        }
        
        return ans;
    }
};