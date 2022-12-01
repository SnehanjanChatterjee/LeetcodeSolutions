class Solution {
private:
    bool isVowel(char &ch) {
        string str = "AEIOUaeiou";
        return (str.find(ch) != string::npos);
    }
public:
    bool halvesAreAlike(string s) {
        int i = 0, j = s.size() - 1, ci = 0, cj = 0;
        while(i < j) {
            if(isVowel(s[i++])) ci++;
            if(isVowel(s[j--])) cj++;
        }
        return ci == cj;
    }
};