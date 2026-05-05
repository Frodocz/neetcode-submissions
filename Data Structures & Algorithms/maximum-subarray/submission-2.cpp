class Solution {
    vector<vector<int>> memo;
public:
    int maxSubArray(vector<int>& nums) {
        // memo.assign(nums.size(), vector<int>(2, -1e7));
        // return dfs(nums, 0, false);
        int n =nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    
        // dp[i][0] -> maxSubArray can start at i or later
        // dp[i][1] -> maxSubArray must start at i 
        dp[n - 1][1] = dp[n - 1][0] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            dp[i][1] = max(nums[i], nums[i] + dp[i + 1][1]);
            dp[i][0] = max(dp[i + 1][0], dp[i][1]);
        }
        return dp[0][0];
    }

    // flag = false => we have not started a subarray yet
    // flag = true => we are currently building a subarray
    int dfs(vector<int>& nums, int i, bool flag)
    {
        if (i == nums.size()) return flag ? 0 : -1e6;
        if (memo[i][flag] != -1e7) return memo[i][flag];
        if (flag)
        {
            memo[i][flag] = max(0, nums[i] + dfs(nums, i + 1, true));
        }
        else
        {
            memo[i][flag] = max(nums[i] + dfs(nums, i + 1, true),
                   dfs(nums, i + 1, false));
        }
        return memo[i][flag];
    }
};
