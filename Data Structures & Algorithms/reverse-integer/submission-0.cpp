class Solution {
public:
    int reverse(int x) {
        long copy = x;
        long res = 0;
        long upper_limit = numeric_limits<int>::max();
        long lower_limit = numeric_limits<int>::min();
        while (copy)
        {
            long last = copy % 10;
            copy /= 10;
            res = 10 * res + last;
            if (res >= upper_limit || res < lower_limit)
                return 0;
        }
        return res;
    }
};
