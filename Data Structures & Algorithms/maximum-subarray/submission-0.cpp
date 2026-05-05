class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return dfs(nums, 0, false);
    }

    // flag = false => we have not started a subarray yet
    // flag = true => we are currently building a subarray
    int dfs(vector<int>& nums, int i, bool flag)
    {
        if (i == nums.size()) return flag ? 0 : -1e6;
        if (flag) return max(0, nums[i] + dfs(nums, i + 1, true));
        return max(nums[i] + dfs(nums, i + 1, true),
                   dfs(nums, i + 1, false));
    }
};
