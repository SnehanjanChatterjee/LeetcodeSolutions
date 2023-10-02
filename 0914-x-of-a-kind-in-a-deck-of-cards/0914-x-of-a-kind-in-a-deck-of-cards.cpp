class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> mp;
        
        for(auto &x: deck) {
            mp[x]++;
        }
        
        int count = 0;
        for(auto i: mp) {
            count = __gcd(i.second, count);
        }
        
        return (count >=2);
    }
};