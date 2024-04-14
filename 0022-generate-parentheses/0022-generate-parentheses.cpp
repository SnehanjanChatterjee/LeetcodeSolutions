class Solution {
public:
    // https://www.youtube.com/watch?v=eyCj_u3PoJE&ab_channel=AdityaVerma
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string ds = "";
        recur(n, n, ans, ds);
        return ans;
    }
    
    void recur(int open, int close, vector<string> &ans, string ds) {
        if(open==0 && close==0) {
            ans.push_back(ds);
            return;
        }
        
        if(open != 0) {
            recur(open-1, close, ans, ds+"(");
        }
        if(close > open) {
            recur(open, close-1, ans, ds+")");
        }
    }
};