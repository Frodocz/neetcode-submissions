class Solution {
    vector<int> cache;
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // int n = cost.size();
        // dp[n] = min(dp[n - 1] + cost[n - 1], dp[n - 2] + cost[n - 2])
        // vector<int> dp(n + 1); 
        cache.assign(cost.size(), -1);
        return min(dfs(cost, 0), dfs(cost, 1));
    }

    int dfs(vector<int>& cost, int i)
    {
        if (i >= cost.size())
        {
            return 0;
        }

        if (cache[i] != -1)
            return cache[i];
        

        cache[i] = cost[i] + min(dfs(cost, i + 1), dfs(cost, i + 2));
        return cache[i];
    }
};
