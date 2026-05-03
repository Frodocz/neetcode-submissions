class Solution {
    static constexpr int INF = 2147483647;
    static constexpr int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> visited;
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == INF)
                {
                    grid[i][j] = bfs(grid, i, j);
                }
            }
        }
    }

    int bfs(vector<vector<int>>& grid, int r, int c)
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});
        vector<vector<int>> visited(m, vector<int>(n));
        visited[r][c] = 1;
        int dist = 0;
        while (!q.empty())
        {
            int num = q.size();
            for (int i = 0; i < num; ++i)
            {
                auto [xr, xc] = q.front(); q.pop();
                if (grid[xr][xc] == 0)
                {
                    // found
                    return dist;
                }
                for (int i = 0; i < 4; ++i)
                {
                    int nr = xr + d[i][0], nc = xc + d[i][1];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n
                        && !visited[nr][nc] && grid[nr][nc] != -1)
                    {
                        visited[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            dist++;
        }
        return INF;
    }
};
