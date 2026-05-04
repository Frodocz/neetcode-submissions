class Solution {
public:
    int climbStairs(int n) {
        // dp[0] = 1 -> no way to choose
        // dp[1] = 1
        // dp[2] = 2
        // dp[n] = dp[n - 1] + dp[n - 2]
        vector<int> dp(n + 1);
        dp[0] = 1; dp[1] = 1; dp[2] = 2;
        for (int i = 3; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
