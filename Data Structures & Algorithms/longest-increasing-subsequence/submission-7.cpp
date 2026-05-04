class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] -> the longest strictly increasing subsequence length
        // keep the index of last element smaller than it
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (nums[j] > nums[i])
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    ans = max(ans, dp[i]);
                }
            }

        }
        return ans;
    }
};
