class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        for (int i = 0; i < 32; ++i)
        {
            uint32_t r = (n >> i) & 1;
            r <<= (31 - i);
            ans |= r;
        }
        return ans;
    }
};
