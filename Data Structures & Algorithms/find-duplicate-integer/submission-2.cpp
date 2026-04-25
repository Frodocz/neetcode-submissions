class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (auto x : nums)
        {
            int idx = abs(x) - 1;
            if (nums[idx] < 0)
                return abs(x);
            nums[idx] = -nums[idx];
        }
        return -1;
    }
};
