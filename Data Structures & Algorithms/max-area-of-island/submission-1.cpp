class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), maxArea = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    int curArea = dfs(grid, i, j);
                    // std::cout << "curArea = " << curArea << " at (" << i << "," << j << ")\n";
                    maxArea = max(maxArea, curArea);
                }
            }
        }
        return maxArea;

    }

    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        int m = grid.size(), n = grid[0].size();
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] != 1)
            return 0;
        grid[r][c] = -1;
        return 1 + dfs(grid, r + 1, c)
                 + dfs(grid, r, c + 1)
                 + dfs(grid, r - 1, c)
                 + dfs(grid, r, c - 1);
    }
};
