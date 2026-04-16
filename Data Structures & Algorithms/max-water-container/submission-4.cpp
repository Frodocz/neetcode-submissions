class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, n = heights.size(), r = n - 1, ans = 0;
        while (l < r)
        {
            ans = max(ans, min(heights[l], heights[r]) * (r - l));
            if (heights[l] < heights[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans;
    }
};
