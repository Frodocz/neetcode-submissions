class Solution {
    int getSquareSum(int n)
    {
        int ans = 0;
        while (n)
        {
            int last = n % 10;
            ans += last * last;
            n /= 10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (!seen.contains(n))
        {
            seen.insert(n);
            n = getSquareSum(n);
            if (n == 1) return true;
        }
        return false;
    }
};
