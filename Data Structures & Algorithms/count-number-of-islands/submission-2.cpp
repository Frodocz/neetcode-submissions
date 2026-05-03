class Solution {
    static constexpr int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    // dfs(grid, i, j);
                    bfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        int m = grid.size(), n = grid[0].size();
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] != '1')
        {
            return;
        }

        grid[r][c] = 'x';
        for (int i = 0; i < 4; ++i)
        {
            dfs(grid, r + d[i][0], c + d[i][1]);
        }
    }

    void bfs(vector<vector<char>>& grid, int r, int c)
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = 'x';
        while (!q.empty())
        {
            auto [xr, xc] = q.front(); q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int nr = xr + d[i][0], nc = xc + d[i][1];
                if (nr < 0 || nc < 0 || nr >= m || nc >= n || grid[nr][nc] != '1')
                    continue;
                q.push({nr, nc});
                grid[nr][nc] = 'x';
            }
        }
        return;
    }
};
