class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        if (n == 0) return 0;

        int l = 0, r = n - 1;
        int leftMax = height[l], rightMax = height[r];

        while (l < r)
        {
            if (leftMax < rightMax)
            {
                l++;
                leftMax = max(leftMax, height[l]);
                ans += leftMax - height[l];
            }
            else
            {
                r--;
                rightMax = max(rightMax, height[r]);
                ans += rightMax - height[r];
            }
        }
        return ans;
    }
};
