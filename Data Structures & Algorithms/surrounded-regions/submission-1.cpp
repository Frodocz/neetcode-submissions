class Solution {
    constexpr static int d[4][2] = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };
public:
    void solve(vector<vector<char>>& board) {
        // dfs from all 'O's in boarder
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i)
        {
            if (board[i][0] == 'O')
            {
                dfs(board, i, 0);
            }

            if (board[i][n - 1] == 'O')
            {
                dfs(board, i, n - 1);
            }
        }

        for (int j = 0; j < n; ++j)
        {
            if (board[0][j] == 'O')
            {
                dfs(board, 0, j);
            }

            if (board[m - 1][j] == 'O')
            {
                dfs(board, m - 1, j);
            }
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int r, int c)
    {
        int m = board.size(), n = board[0].size();
        if (r < 0 || c < 0 || r >= m || c >= n || board[r][c] != 'O')
        {
            return;
        }

        board[r][c] = '#';

        for (int i = 0; i < 4; ++i)
        {
            int nr = r + d[i][0], nc = c + d[i][1];
            dfs(board, nr, nc);
        }
    }
};
