class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (temperatures[j] > temperatures[i])
                {
                    ans[i] = j - i;
                    break;
                }
            }
        }
        return ans;
    }
};
