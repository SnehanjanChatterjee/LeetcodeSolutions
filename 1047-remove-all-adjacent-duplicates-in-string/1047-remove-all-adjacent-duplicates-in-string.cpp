class Solution {
public:
    string removeDuplicates(string s) {
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
};