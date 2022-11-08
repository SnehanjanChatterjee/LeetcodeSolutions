class Solution {
private:
    bool isSmallCase(char ch) {
        return ch >= 97 && ch <= 122;
    }
    bool isUpperCase(char ch) {
        return ch >= 65 && ch <= 90;
    }
public:
    string makeGood(string s) {
        for(int i=0; i<s.size()-1; i++) {
            if((tolower(s[i])==tolower(s[i+1])) && ((isSmallCase(s[i]) && isUpperCase(s[i+1])) || (isUpperCase(s[i]) && isSmallCase(s[i+1])))) {
                s.erase(i, 2);
                if(s.size() == 0) break;
                if(i > 0) i -= 2;
                else i -= 1;
            }
        }
        
        return s;
    }
};