class Solution {
private:
void recur(int ind, int n, vector<string> &ans, string &s, string convertedS) {
    if(ind == n) {
        ans.push_back(convertedS);
        return;
    }
    
    if(s[ind] >= 48 && s[ind] <= 57) {
        convertedS += s[ind];
        recur(ind+1, n, ans, s, convertedS);
    } else {
        // Not Take
        convertedS += s[ind];
        recur(ind+1, n, ans, s, convertedS);
        
        // Take
        convertedS.pop_back();
        if(islower(s[ind])) convertedS += toupper(s[ind]);
        else convertedS += tolower(s[ind]);
        recur(ind+1, n, ans, s, convertedS);
    }
}
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string convertedS = "";
        int n = s.size();
        recur(0, n, ans, s, convertedS);
        return ans;
    }
};