class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq_ump;
        int ans = 0;
        
        for(int &task: tasks) freq_ump[task]++;
        
        for(auto [num, freq]: freq_ump) {
            if(freq == 1) return -1;
            else if(freq % 3 == 0) ans += (freq/3);
            else ans += ((freq/3) + 1);
        }
        
        return ans;
    }
};