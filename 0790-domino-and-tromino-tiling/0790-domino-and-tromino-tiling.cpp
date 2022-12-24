class Solution {
public:
    // https://leetcode.com/problems/domino-and-tromino-tiling/discuss/1620809/PythonJAVACC%2B%2B-DP-oror-Image-Visualized-Explanation-oror-100-Faster-oror-O(N)
    int numTilings(int n) {
        if (n == 1) return 1;
        unsigned int dp[n]; dp[0] = 1; dp[1] = 2;
        unsigned int dpa[n]; dpa[1] = 1;
        for (int i = 2; i < n; i ++) {
            dp[i] = (dp[i - 1] + dp[i - 2] + dpa[i - 1] * 2) % 1000000007;
            dpa[i] = (dp[i - 2] + dpa[i - 1]) % 1000000007;
        }
        return dp[n - 1];
    }
};