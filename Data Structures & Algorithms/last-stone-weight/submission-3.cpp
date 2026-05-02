class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_heap;
        for (auto x : stones)
        {
            max_heap.push(x);
        }

        while (max_heap.size() > 1)
        {
            int s0 = max_heap.top(); max_heap.pop();
            int s1 = max_heap.top(); max_heap.pop();
            if (s0 == s1) continue;
            else max_heap.push(s0 - s1);
        }
        return max_heap.empty() ? 0 : max_heap.top();
    }
};
