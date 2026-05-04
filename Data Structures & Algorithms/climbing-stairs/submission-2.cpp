class Solution {
public:
    int climbStairs(int n) {
        // dp[0] = 1 -> no way to choose
        // dp[1] = 1
        // dp[2] = 2
        // dp[n] = dp[n - 1] + dp[n - 2]
        int dp_i_2 = 1, dp_i_1 = 1;
        // dp[0] = 1; dp[1] = 1; dp[2] = 2;
        for (int i = 0; i < n - 1; ++i)
        {
            // dp[i] = dp[i - 1] + dp[i - 2];
            // int dp_i = dp_i_1 + dp_i_2;
            int tmp = dp_i_1;
            dp_i_1 = dp_i_1 + dp_i_2;
            dp_i_2 = tmp;
        }
        return dp_i_1;
    }
};
