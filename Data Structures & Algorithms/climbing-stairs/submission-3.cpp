class Solution {
    vector<int> cache;
public:
    int climbStairs(int n) {
        // dp[0] = 1 -> no way to choose
        // dp[1] = 1
        // dp[2] = 2
        // dp[n] = dp[n - 1] + dp[n - 2]
        cache.resize(n, -1);
        return dfs(n, 0);
    }

    int dfs(int n, int i)
    {
        if (i >= n) return i == n;
        if (cache[i] != -1) return cache[i];
        cache[i] = dfs(n, i + 1) + dfs(n, i + 2);
        return cache[i];
    }
};
