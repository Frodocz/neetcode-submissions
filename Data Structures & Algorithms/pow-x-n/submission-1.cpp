class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (x == 0.) return 0.;
        double res = 1.;
        long pow = abs(n);
        while (pow)
        {
            if (pow & 1)
            {
                res *= x;
            }
            x *= x;
            pow >>= 1;
        }
        return n > 0 ? res : 1 / res;
    }
};
