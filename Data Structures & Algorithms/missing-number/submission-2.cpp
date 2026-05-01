class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), sum = n;
        for (int i = 0; i < n; ++i)
        {
            sum += i - nums[i];
        }
        return sum;
    }
};
