class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> ump;
        
        for(char &ch: s) ump[ch]++;
        
        priority_queue<pair<int, char>> pq;
        
        for(auto [ch, freq]: ump) {
            // cout<<"freq = "<<freq<<" ch = "<<ch<<endl;
            pq.push({freq, ch});
        }
        
        string ans = "";
        
        // cout<<"Iterating pq"<<endl;
        while(!pq.empty()) {
            auto itr = pq.top();
            int freq = itr.first;
            char ch = itr.second; 
            // cout<<"freq = "<<freq<<" ch = "<<ch<<endl;
            pq.pop();
            while(freq--) ans += ch;
        }
        
        return ans;
    }
};