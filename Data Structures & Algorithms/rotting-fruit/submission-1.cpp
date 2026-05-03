class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0, fresh = 0;
        queue<pair<int, int>> q;
        int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        // start from all rotten and expand using bfs until stopped 
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    fresh++;
                }
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }

        while (fresh > 0 && !q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                auto [r, c] = q.front(); q.pop();
                for (int i = 0; i < 4; ++i)
                {
                    int nr = r + d[i][0], nc = c + d[i][1];
                    if (nr >= 0 && nc >= 0 && nr < m && nc < n
                        && grid[nr][nc] == 1)
                    {
                        // only rot fresh one
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                    }
                }
            }
            time++;
        }

        return fresh == 0 ? time : -1;
    }
};
