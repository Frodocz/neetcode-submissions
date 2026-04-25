class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + (r - l) /2;
            if (nums[mid] < nums[r])
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        int pivot = l;
        int res = binary_search(nums, 0, pivot - 1, target);
        if (res != -1) return res;
        res = binary_search(nums, pivot, n - 1, target);
        return res;
    }

    int binary_search(vector<int>& nums, int l, int r, int target)
    {
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};
