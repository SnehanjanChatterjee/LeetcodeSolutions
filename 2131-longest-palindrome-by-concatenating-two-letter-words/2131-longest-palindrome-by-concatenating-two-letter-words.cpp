class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> ump;
        int count = 0;
        
        for(auto s: words) ump[s]++;
        
        for(auto s: words) {
            
            string rev(s);
            reverse(rev.begin(), rev.end());
            
            if(ump.find(s)!=ump.end() && ump.find(rev)!=ump.end()) {
                
                if(rev == s && ump[s] > 1) {
                    int minC = (ump[s] % 2 == 0) ? ump[s] : (ump[s]-1);
                    count += (2 * minC);
                    ump[s] -= minC;
                }
                else if(rev != s && ump[s] > 0 && ump[rev] > 0) {
                    int minC = min(ump[rev], ump[s]);
                    count += (4 * minC);

                    ump[rev] -= minC;
                    ump[s] -= minC;
                }
                
            }
        }
        
        for(auto s: words) {
            string rev(s);
            reverse(rev.begin(), rev.end());
            if(s == rev && ump[s] > 0) {
                count += 2;
                break;
            }
        }
        
        return count;
    }
};