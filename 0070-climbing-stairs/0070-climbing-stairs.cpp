class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        
        //Recursive -> TLE
        // return recursive(n);
        
        // Top-Down -> Runs
        // return topDownDP(n, dp);
        
        // Bottom-Up Tabulation -> Faster
        // return bottomUpDP(n, dp);
        
        // Space Optimized -> Fastest
        return spaceOptimizedDP(n);
        
    }
    
    int recursive(int n) {
        if(n <= 1) return 1;
        return recursive(n-1) + recursive(n-2);
    }
    
    int topDownDP(int n, vector<int> &dp) {
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = topDownDP(n-1, dp) + topDownDP(n-2, dp);
    }
    
    int bottomUpDP(int n, vector<int> &dp) {
        dp[0] = 1; dp[1] = 1;
        for(int i=2; i<=n; i++) {
          dp[i] = dp[i-1] + dp[i-2];  
        }
        return dp[n];
    }
    
    int spaceOptimizedDP(int n) {
        int first = 1, second = 1, third = 0;
        for(int i=2; i<=n; i++) {
            third = first + second;
            first = second;
            second = third;
        }
        return second;
                                   
    }
};