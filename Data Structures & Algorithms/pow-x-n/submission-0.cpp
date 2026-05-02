class Solution {
    double helper(double x, int n)
    {
        double ans = 1.;
        while (n--)
        {
            ans *= x;
        }
        return ans;
    }
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (x == 0.) return 0.;
        else if (n > 0)
        {
            return helper(x, n);
        }
        else
        {
            return 1.0 / helper(x, abs(n));
        }
    }
};
