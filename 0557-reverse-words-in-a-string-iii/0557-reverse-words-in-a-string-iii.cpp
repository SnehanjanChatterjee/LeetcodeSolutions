class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int startOfWord = 0, endofWord = 0;
        for(endofWord=0; endofWord<n; endofWord++) {
            if(s[endofWord] == ' ') {
                reverse(s.begin() + startOfWord, s.begin() + endofWord);
        
                endofWord = endofWord + 1;
                startOfWord = endofWord;
            }
        }
        reverse(s.begin() + startOfWord, s.begin() + endofWord);
        return s;
    }
};