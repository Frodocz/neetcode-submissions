class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool rowZero = false; // first row should be all zeros?
        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                if (matrix[r][c] == 0)
                {
                    matrix[0][c] = 0;
                    if (r > 0)
                    {
                        matrix[r][0] = 0;
                    }
                    else
                    {
                        rowZero = true;
                    }
                }
            }
        }

        for (int r = 1; r < m; ++r)
        {
            for (int c = 1; c < n; ++c)
            {
                if (matrix[0][c] == 0 || matrix[r][0] == 0)
                {
                    matrix[r][c] = 0;
                }
            }
        }

        if (matrix[0][0] == 0) {
            for (int r = 0; r < m; r++) {
                matrix[r][0] = 0;
            }
        }

        if (rowZero) {
            for (int c = 0; c < n; c++) {
                matrix[0][c] = 0;
            }
        }
    }
};
