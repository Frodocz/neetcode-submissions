class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), xorr = n;
        for (int i = 0; i < n; ++i)
        {
            xorr ^= i;
            xorr ^= nums[i];
        }
        return xorr;
    }
};
