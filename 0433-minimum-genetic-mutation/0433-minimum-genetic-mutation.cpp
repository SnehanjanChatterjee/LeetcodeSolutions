class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int step = 0;
        unordered_set<string> us(bank.begin(), bank.end());
        queue<string> q;
        
        q.push(start);
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                string original = q.front();
                q.pop();

                if(original == end) {
                    return step;
                }

                us.erase(original);
                
                for(int i=0; i<original.size(); i++) {
                    string mutated = original;
                    for(char ch: {'A', 'C', 'G', 'T'}) {
                        mutated[i] = ch;
                        if(us.find(mutated) != us.end()) {
                            q.push(mutated);
                        }
                    }
                }
            }
            step++;
        }
        
        return -1;
    }
};