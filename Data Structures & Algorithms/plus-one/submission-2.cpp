class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if (digits[n - 1] != 9)
        {
            digits[n - 1]++;
            return digits;
        }

        vector<int> res;
        res.reserve(n + 1);
        int carry = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            int val = digits[i] + carry;
            res.push_back(val % 10);
            carry = (val == 10);
        }

        if (carry) res.push_back(1);
        reverse(res.begin(), res.end());
        return res;
    }
};
