class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        unordered_map<char, int> ump;
        int n = s.size();

        // For each char of 1st string, increase its count in map
        // For each char of 2nd string, decrase its count in map
        for(int i = 0; i < n; i++) {
            ump[s[i]]++;
            ump[t[i]]--;
        }

        // If in map finally there is a char whose count is 1, 
        // that means either of the strings s or t has that char in extra (so not an anagram)
        for(auto &x: ump) {
            if(x.second) {
                return false;
            }
        }

        return true;
    }
};