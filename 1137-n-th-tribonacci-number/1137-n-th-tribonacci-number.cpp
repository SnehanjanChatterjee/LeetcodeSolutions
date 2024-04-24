class Solution {
private:
    // TLE
    int recur(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        
        return recur(n - 1) + recur(n - 2) + recur(n - 3);
    }
    
    int dp(int n) {
        if(n == 0) return 0;
        if(n <= 2) return 1;
        
        int dp[n+1];
        dp[0] = 0;
        dp[1] = dp[2] = 1;
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
        }
        return dp[n];
    }
public:
    int tribonacci(int n) {
        // return recur(n);
        
        return dp(n);
    }
};