class Solution {
    static constexpr int INF = 2147483647;
    static constexpr int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> visited;
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 0)
                {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            auto [r, c] = q.front(); q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int nr = r + d[i][0], nc = c + d[i][1];
                if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == INF)
                {
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};
