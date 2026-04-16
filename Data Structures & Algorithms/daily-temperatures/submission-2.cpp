class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);

        stack<pair<int, int>> st; // {temp, index}

        for (int i = 0; i < n; ++i)
        {
            int t = temperatures[i];
            while (!st.empty() && st.top().first < t)
            {
                auto [temp, index] = st.top();
                st.pop();
                ans[index] = i - index;
            }
            st.push({t, i});
        }
        return ans;
    }
};
