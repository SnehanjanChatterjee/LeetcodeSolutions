class Solution {
public:
    // https://leetcode.com/problems/orderly-queue/solutions/2778309/faster-than-100-0ms/
    // https://leetcode.com/problems/orderly-queue/solutions/2784103/most-easy-c-solution-beginner-friendly-very-easy-to-understand/
    string orderlyQueue(string s, int k) {
        if(k>1) {
            sort(s.begin(),s.end());
            return s;
        }
        if(k==1) { // for k == 1 we have to check for each and every possible rotation.
            string lexMin = s;
            int size = s.size();
            while(size--) {
                char firstChar = s[0];

                s.erase(0,1); // Remove 1st char
                s.push_back(firstChar); // Push 1st char at end
                
                lexMin = min(lexMin,s); // Check if newly generated string is the lexicographical min
            }
            return lexMin;
        }
        return s;
    }
};