class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int sum = 0;
        
        // Push all piles into priority queue such that the max pile appear at top
        // Calculate sum also
        for(int &pile: piles) {
            pq.push(pile);
            sum += pile;
        }
        
        // At each iteration fetch fetch pile (i.e. top of priority queue) and pop it
        // Remove stones from that pile and push again into priority queue
        // Modify sum along with this
        while(k--) {
            int oldPile = pq.top();
            int newPile = oldPile - (oldPile / 2);
            
            sum = sum - oldPile + newPile;
            
            pq.pop();
            pq.push(newPile);
        }
        
        return sum;
    }
};