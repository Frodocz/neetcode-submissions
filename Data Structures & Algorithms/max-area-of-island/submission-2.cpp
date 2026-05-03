class Solution {
    constexpr static int d[4][2] = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), maxArea = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    int curArea = bfs(grid, i, j);
                    // int curArea = dfs(grid, i, j);
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

    int bfs(vector<vector<int>>& grid, int r, int c)
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = -1;
        int area = 0;
        while (!q.empty())
        {
            auto [xr, xc] = q.front(); q.pop();
            area++;
            for (int i = 0; i < 4; ++i)
            {
                int nr = xr + d[i][0];
                int nc = xc + d[i][1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1)
                {
                    q.push({nr, nc});
                    grid[nr][nc] = -1;
                }
            }
        }
        return area;
    }
};
