class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        vector<int> left(n), right(n);
        for (int i = 1; i < n; ++i)
        {
            left[i] = max(left[i - 1], height[i - 1]);
        }

        for (int i = n - 2; i >= 0; --i)
        {
            right[i] = max(right[i + 1], height[i + 1]);
            int bar = min(left[i], right[i]);
            ans += bar > height[i] ? bar - height[i] : 0;
        }
        return ans;
    }
};
