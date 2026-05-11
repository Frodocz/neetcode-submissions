class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        dfs(nums, 0, cur);
        return ans;
    }

    void dfs(vector<int>& nums, int i, vector<int>& cur)
    {
        if (i == nums.size())
        {
            ans.push_back(cur);
            return;
        }

        cur.push_back(nums[i]); // use
        dfs(nums, i + 1, cur);
        cur.pop_back();
        dfs(nums, i + 1, cur); // not use
    }
};
