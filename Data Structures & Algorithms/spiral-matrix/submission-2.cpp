class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(); // m * n
        int l = 0, r = n, u = 0, b = m;
        vector<int> ans; ans.reserve(m * n);
        while (l < r && u < b)
        {
            for (int i = l; i < r; ++i) // [u][i]
            {
                ans.emplace_back(matrix[u][i]);
            }
            u++;
            for (int i = u; i < b; ++i) // [i][r]
            {
                ans.emplace_back(matrix[i][r - 1]);
            }
            r--;
            if (!(l < r && u < b)) break;
            for (int i = r - 1; i >= l; --i) // [b][i]
            {
                ans.emplace_back(matrix[b - 1][i]);
            }
            b--;
            for (int i = b - 1; i >= u; --i) // [i][l]
            {
                ans.emplace_back(matrix[i][l]);
            }
            l++;
        }
        return ans;
    }
};
