class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int sum = 0;
        
        for(int &pile: piles) {
            pq.push(pile);
            sum += pile;
        }
        
        while(k--) {
            int oldNum = pq.top();
            int newNum = oldNum - (oldNum / 2);
            sum = sum - oldNum + newNum;
            pq.pop();
            pq.push(newNum);
        }
        
        return sum;
    }
};