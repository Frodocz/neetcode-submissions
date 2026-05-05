class Solution {
    unordered_map<int, bool> memo;
public:
    bool canJump(vector<int>& nums) {
        // memo[i] -> if we can reach end of nums at index i
        // return dfs(nums, 0);

        // dp[i] -> if at index i we can reach end of nums
        int n = nums.size();
        // vector<bool> dp(n, false);
        // dp[n - 1] = true;
        // for (int i = n - 2; i >= 0; --i)
        // {
        //     int end = min(n - 1, i + nums[i]);
        //     for (int j = i + 1; j <= end; ++j)
        //     {
        //         if (dp[j])
        //         {
        //             dp[i] = true;
        //             break;
        //         }
        //     }
        // }
        // return dp[0];

        // greedy solution
        int goal = n - 1;
        for (int i = n - 2; i >= 0; --i)
        {
            if (i + nums[i] >= goal)
            {
                goal = i;
            }
        }
        return goal == 0;
    }

    bool dfs(vector<int>& nums, int i)
    {
        if (i == nums.size() - 1)
        {
            return true;
        }

        if (memo.count(i)) return memo[i];

        if (nums[i] == 0) return false;

        int end = min((int)nums.size() - 1, i + nums[i]);
        for (int j = i + 1; j <= end; ++j)
        {
            if (dfs(nums, j))
            {
                memo[i] = true;
                return true;
            }
        }
        memo[i] = false;
        return false;
    }
};
