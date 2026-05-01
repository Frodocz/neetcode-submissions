class Solution {
    long getSquareSum(long n)
    {
        long ans = 0;
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
        unordered_set<long> seen;
        while (n != 1)
        {
            long sum = getSquareSum(n);
            if (sum == 1)
            {
                break;
            }
            if (seen.contains(sum))
            {
                return false;
            }
            seen.insert(sum);
            n = sum;
        }
        return true;
    }
};
