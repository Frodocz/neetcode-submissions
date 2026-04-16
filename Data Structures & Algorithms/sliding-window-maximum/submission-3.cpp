class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        deque<int> dq;
        int l = 0, r = 0;
        while (r < n)
        {
            while (!dq.empty() && nums[dq.back()] <= nums[r])
            {
                dq.pop_back();
            }
            dq.push_back(r);

            int l = r - k + 1;
            if (l < 0)
            {
                r++;
                continue;
            }

            while (!dq.empty() && dq.front() < l)
            {
                dq.pop_front();
            }
            ans[l] = nums[dq.front()];

            ++r;
        }

        return ans;
    }
};
