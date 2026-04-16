class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[day][hold] -> at the end of day i, if I hold any stock
        // dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        // dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);

        int n = prices.size();
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        // dp[0][0] = 0; dp[0][1] = INT_MIN;
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, -prices[i]);
        }
        // return dp[n][0];
        return dp_i_0;
    }
};
