class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans = 0;
        
        for(int &cost: costs) {
            if((coins - cost) < 0) break;
            ans++;
            coins -= cost;
        }
        
        return ans;
    }
};