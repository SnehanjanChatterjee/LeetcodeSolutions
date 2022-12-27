class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int n = rocks.size(), c = 0;
        
        for(int i=0; i<n; i++) {
            minHeap.push(capacity[i] - rocks[i]);
        }
        
        while(!minHeap.empty()) {
            int diff = minHeap.top();
            
            if((additionalRocks - diff) < 0) {
                break;
            } else {
                minHeap.pop();
                c++;
                additionalRocks -= diff;
            }
        }
        
        return c;
    }
};