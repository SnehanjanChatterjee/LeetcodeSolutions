class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int step = 0;
        unordered_set<string> us(bank.begin(), bank.end());
        vector<string> forErase;
        queue<string> q;
        
        q.push(start);
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                string original = q.front();
                q.pop();

                if(original == end) {
                    // cout<<"Found end = "<<end<<", step = "<<step<<endl;
                    return step;
                }

                us.erase(original);
                
                for(int i=0; i<original.size(); i++) {
                    string mutated = original;
                    // if(start[i] != end[i]) {
                        for(char ch: {'A', 'C', 'G', 'T'}) {
                            mutated[i] = ch;
                            // cout<<original<<" Mutated to "<<mutated<<endl;
                            // for(int s=0; s<bank.size(); s++) {
                            //     if(bank[s] == mutated) {
                            //         q.push(mutated);
                            //         // step++;
                            //         cout<<mutated<<" Found in bank, step = "<<step<<endl;
                            //     }
                            // }
                            if(us.find(mutated) != us.end()) {
                                q.push(mutated);
                                // cout<<mutated<<" Found in bank, step = "<<step<<endl;
                            }
                        }
                        // mutated = original;
                    // }

                }
            }
            step++;
        }
        
        return -1;
    }
};