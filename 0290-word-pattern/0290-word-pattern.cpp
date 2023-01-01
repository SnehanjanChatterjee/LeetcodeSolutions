class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string word = "";
        unordered_map<char, set<string>> ump_char;
        unordered_map<string, set<char>> ump_str;
        int ind = 0;

        for (auto &x : s) {
            if (x == ' ')
            {
                ump_char[pattern[ind]].insert(word);
                ump_str[word].insert(pattern[ind]);
                
                if(ump_char[pattern[ind]].size() > 1) return false;
                if(ump_str[word].size() > 1) return false;
                
                ind++;
                word = "";
            }
            else {
                word = word + x;
            }
        }
        ump_char[pattern[ind]].insert(word);
        ump_str[word].insert(pattern[ind]);
        
        if(ump_char[pattern[ind]].size() > 1) return false;
        if(ump_str[word].size() > 1) return false;

        if(ind < (pattern.size() - 1)) return false;

        return true;
    }
};