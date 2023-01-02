class Solution {    
public:
    bool detectCapitalUse(string word) {
        bool firstCharCap = isupper(word[0]);
        bool allCap = true, allSmall = true;
        
        for(int i=1; i<word.size(); i++) {
            if(isupper(word[i])) allSmall = false;
            else if(!isupper(word[i])) allCap = false;
        }
        
        return ((firstCharCap && allCap) || (firstCharCap && allSmall) || (allSmall));
    }
};