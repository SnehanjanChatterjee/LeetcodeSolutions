class Solution {
private:
    // TC --> O(NX2)
    // SC --> O(NX2) + O(N) [Auxilary stack space]
    int topDownDP(int ind, int buy, vector<int>& prices, vector<vector<int>> &dp) {
        if(ind >= prices.size()) return 0;
        
        if(dp[ind][buy] != -1) return dp[ind][buy];
        
        int profit = 0;
        if(buy) {
            int take = (-1)*prices[ind] + topDownDP(ind + 1, 0, prices, dp);
            int notTake = 0 + topDownDP(ind + 1, 1, prices, dp);
            profit = max(take, notTake);
        }
        else {
            int take = prices[ind] + topDownDP(ind + 2, 1, prices, dp);
            int notTake = 0 + topDownDP(ind + 1, 0, prices, dp);
            profit = max(take, notTake);
        }
        return dp[ind][buy] = profit;
    }
    
    // TC --> O(NX2)
    // SC --> O(NX2)
    int bottomUpDP(vector<int>& prices, int n) {
        vector<vector<int>> dp(n + 2, vector<int> (2, 0));
        dp[n][1] = dp[n][1] = 0;
        
        for(int ind = n-1; ind >= 0; ind--) {
            for(int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if(buy) {
                    int take = (-1)*prices[ind] + dp[ind + 1][0];
                    int notTake = 0 + dp[ind + 1][1];
                    profit = max(take, notTake);
                }
                else {
                    int take = prices[ind] + dp[ind + 2][1];
                    int notTake = 0 + dp[ind + 1][0];
                    profit = max(take, notTake);
                }
                dp[ind][buy] = profit;
            }
        }
        
        return dp[0][1];
    }
    
    // TC --> O(N)
    // SC --> O(N)
    int bottomUpWithOneLoopDP(vector<int>& prices, int n) {
        vector<vector<int>> dp(n + 2, vector<int> (2, 0));
        
        for(int ind = n-1; ind >= 0; ind--) {
            dp[ind][1] = max((-prices[ind] + dp[ind + 1][0]), (0 + dp[ind + 1][1]));
            dp[ind][0] = max((prices[ind] + dp[ind + 2][1]), (0 + dp[ind + 1][0]));
        }
        
        return dp[0][1];
    }
    
    // TC --> O(N)
    // SC --> O(N)
    int spaceOptimizedBottomUpWithOneLoopDP(vector<int>& prices, int n) {
        vector<int> after2(2, 0);
        vector<int> after1(2, 0);
        vector<int> cur(2, 0);
        
        for(int ind = n-1; ind >= 0; ind--) {
            cur[1] = max((-prices[ind] + after1[0]), (0 + after1[1]));
            cur[0] = max((prices[ind] + after2[1]), (0 + after1[0]));
            
            after2 = after1;
            after1 = cur;
        }
        
        return after1[1];
    }
    
public:
    int maxProfit(vector<int>& prices) {
        
        // Unlimited transactions with cooldown
        
        // Same as "Best Time to Buy and Sell Stock II" problem
        // Just one small change. After selling can't go to next index. So, go to (ind + 2).
        // Handle this in base case also as ind can become >= n
        
        int n = prices.size();
        
        // vector<vector<int>> dp(n, vector<int> (2, -1));
        // return topDownDP(0, 1, prices, dp);
        
        // return bottomUpDP(prices, n);
        
        // return bottomUpWithOneLoopDP(prices, n);
        
        return spaceOptimizedBottomUpWithOneLoopDP(prices, n);
    }
};