class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0], n = nums.size();
        int curMax = 1, curMin = 1;
        for (int x : nums)
        {
            int tmpMax = curMax * x, tmpMin = curMin * x;
            curMax = max(max(tmpMax, tmpMin), x);
            curMin = min(min(tmpMax, tmpMin), x);
            ans = max(ans, curMax);
        }
        return ans;
    }
};
