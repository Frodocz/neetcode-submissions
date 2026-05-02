class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size();
        vector<string> ans;

        for (auto& word: words)
        {
            bool found = false;
            for (int r = 0; r < m && !found; ++r)
            {
                for (int c = 0; c < n; ++c)
                {
                    if (board[r][c] != word[0]) continue;
                    if (backtrack(board, r, c, word, 0))
                    {
                        ans.push_back(word);
                        found = true;
                        break;
                    }
                }
            }
        } 
        return ans;
    }

    bool backtrack(vector<vector<char>>& board, int r, int c, string&word, int i)
    {
        if (i == word.size()) return true;
        int m = board.size(), n = board[0].size();
        if (r < 0 || c < 0 || r >= m || c >= n || board[r][c] != word[i])
            return false;
        board[r][c] = '*';
        bool ans = backtrack(board, r - 1, c, word, i + 1) ||
                   backtrack(board, r + 1, c, word, i + 1) ||
                   backtrack(board, r, c - 1, word, i + 1) ||
                   backtrack(board, r, c + 1, word, i + 1);
        board[r][c] = word[i];
        return ans;
    }
};
