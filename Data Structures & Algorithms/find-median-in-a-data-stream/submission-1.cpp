class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> minHeap; // top half values
    priority_queue<int> maxHeap; // smallest half values
public:
    MedianFinder() {
        // make sure top half minHeap is always filled first
    }
    
    void addNum(int num) {
        if (minHeap.empty())
        {
            minHeap.push(num);
            return;
        }

        if (minHeap.size() != maxHeap.size())
        {
            // minHeap size > maxHeap size
            // compare the min in top half with num,
            // insert smaller one to smallest half
            int upper_min = minHeap.top();
            if (upper_min < num)
            {
                minHeap.pop();
                minHeap.push(num);
                maxHeap.push(upper_min);
            }
            else
            {
                maxHeap.push(num);
            }
        }
        else
        {
            // if same size, compare the max in smallest half with num,
            // insert bigger one to top half
            int lower_max = maxHeap.top();
            if (lower_max > num)
            {
                maxHeap.pop();
                minHeap.push(lower_max);
                maxHeap.push(num);
            }
            else
            {
                minHeap.push(num);
            }
        }
    }
    
    double findMedian() {
        int upper_size = minHeap.size();
        int lower_size = maxHeap.size();
        int total = upper_size + lower_size;
        if (total & 1)
        {
            return minHeap.top();
        }
        else
        {
            return static_cast<double>(minHeap.top() + maxHeap.top()) / 2.0;
        }
    }
};
