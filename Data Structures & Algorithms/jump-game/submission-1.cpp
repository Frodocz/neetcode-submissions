class Solution {
    unordered_map<int, bool> memo;
public:
    bool canJump(vector<int>& nums) {
        // memo[i] -> if we can reach end of nums at index i
        return dfs(nums, 0);
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
