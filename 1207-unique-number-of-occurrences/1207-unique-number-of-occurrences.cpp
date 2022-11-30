class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> frequency;
        unordered_set<int> s;
        
        for(auto &x: arr) frequency[x]++;
        
        for(auto [num, freq]: frequency) {
            auto itr = s.insert(freq);
            if(!itr.second) return false;
        }
        
        return true;
    }
};