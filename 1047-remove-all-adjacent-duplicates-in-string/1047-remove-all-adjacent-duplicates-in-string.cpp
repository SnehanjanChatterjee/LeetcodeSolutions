class Solution {
private:
    string soln1(string s) {
        int size = s.size();
        for(int i=0; i<size-1; i++) {
            if(s[i] == s[i+1]) {
                s.erase(i, 2);
                if(s.size() == 0) break;
                if(i == 0) i -=1;
                else i -= 2;
            }
        }
        return s;
    }
    
    string soln2(string s) {
        int size = s.size();
        string ans;
        for(char &ch: s) {
            if(ans.size() == 0 || ans.back() != ch) {
                ans.push_back(ch);
            }
            else if(ans.back() == ch) {
                ans.pop_back();
            }
        }
        return ans;
    }
public:
    string removeDuplicates(string s) {
        // return soln1(s);
        
        return soln2(s);
    }
};