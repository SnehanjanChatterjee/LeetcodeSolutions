class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        
        for(string& token: tokens) {
            if(token == "+" || token == "-" || token == "/" || token  == "*") {
                long y = st.top();
                st.pop();
                long x = st.top();
                st.pop();
                if(token == "+") st.push(x + y);
                if(token == "-") st.push(x - y);
                if(token == "/") st.push(x / y);
                if(token == "*") st.push(x * y);
            } else {
                st.push(stol(token));
            }
        }
        return st.top();
    }
};