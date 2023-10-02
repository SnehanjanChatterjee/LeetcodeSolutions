class Solution {
public:
     // (Good) https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/discuss/1609224/C%2B%2B-Easy-Solution-or-Accepted
    // https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/discuss/1929514/Easy-Step-by-Step-Explanation
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;
        
        for(int d : deck) {
            m[d]++;    // map created with frequency of each card no.
        }
        
        int gcd = m[deck[0]];
        for(auto i : m) {
            gcd = __gcd(gcd, i.second);    // doing gcd with the frequency of all the cards
        }
        
        return gcd != 1;    // if gcd is not equal to 1 it means we can create groups of size >= 2.
        
        // E.g deck = [1,1,1,1,3,3,3,3,3,3]
        // No.  Frequency
        // 1   -   4
        // 3   -   6
        // So we can divide in groups as:
        // [1,1], [1,1], [3,3], [3,3], [3,3]
        // So, that's why you may notice now, we can create group of at least gcd(4, 6)
    }
};