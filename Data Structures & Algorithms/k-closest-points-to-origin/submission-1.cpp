class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](vector<int>& p1, vector<int>& p2)
        {
            return p1[0] * p1[0] + p1[1] * p1[1] < p2[0] * p2[0] + p2[1] * p2[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> min_heap(cmp);
        for (auto& p : points)
        {
            min_heap.push(p);
            if (min_heap.size() > k)
            {
                min_heap.pop();
            }
        }
        vector<vector<int>> ans;
        ans.reserve(min_heap.size());
        while (!min_heap.empty())
        {
            ans.push_back(min_heap.top());
            min_heap.pop();
        }
        return ans;
    }
};
