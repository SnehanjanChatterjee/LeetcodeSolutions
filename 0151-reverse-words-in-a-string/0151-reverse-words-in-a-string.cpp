class Solution {
public:
    string reverseWords(string s) {
        vector<string> splittedWords;
        int n = s.size();
        int start=0, end=0;

        while(start<n && end<n) {
            while(start<n && s[start] == ' ') start++;

            end = start + 1;
            
            while(end<n && s[end] != ' ') end++;

            string word = s.substr(start, end-start);
            
            splittedWords.push_back(word);
            
            start = end + 1;
        }
        
        string ans = "";
        for(int i=splittedWords.size()-1; i>0; i--) {
            if(splittedWords[i].size() > 0) {
                ans += (splittedWords[i] + " ");
            }
        }
        
        if(splittedWords[0].size() > 0) {
            ans += splittedWords[0];
        }
        
        return ans;
    }
};