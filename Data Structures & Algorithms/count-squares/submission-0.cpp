class CountSquares {
    unordered_map<long, int> pointsCnt;
    vector<vector<int>> points;

    long getKey(int x, int y)
    {
        return (static_cast<long>(x) << 32) | (static_cast<long>(y));
    }
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        pointsCnt[getKey(point[0], point[1])]++;
        points.push_back(point);
    }
    
    int count(vector<int> point) {
        int res = 0;
        int px = point[0], py = point[1];
        for (const auto& pt : points)
        {
            int x = pt[0], y = pt[1];
            if (abs(py - y) != abs(px - x) || x == px || y == py)
            {
                continue;
            }
            res += pointsCnt[getKey(x, py)] * pointsCnt[getKey(px, y)];
        }
        return res;
    }
};
