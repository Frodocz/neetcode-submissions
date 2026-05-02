class KthLargest {
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int k_;
public:
    KthLargest(int k, vector<int>& nums)
        : k_(k) {
        for (auto x : nums)
        {
            min_heap.push(x);
            if (min_heap.size() > k)
            {
                min_heap.pop();
            }
        }
    }
    
    int add(int val) {
        min_heap.push(val);
        if (min_heap.size() > k_)
        {
            min_heap.pop();
        }
        return min_heap.top();
    }
};
