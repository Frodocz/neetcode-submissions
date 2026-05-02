class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> rows(m), cols(n);
        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                if (matrix[r][c] == 0)
                {
                    rows[r] = 1;
                    cols[c] = 1;
                }
            }
        }

        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                if (rows[r] || cols[c])
                {
                    matrix[r][c] = 0;
                }
            }
        }
    }
};
