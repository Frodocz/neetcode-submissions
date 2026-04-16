class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int n = s.size(), l = 0, r = 0, maxf = 0, ans = 0;
        while (r < n)
        {
            char c = s[r];
            count[c]++;
            maxf = max(maxf, count[c]);

            while (r - l + 1 - maxf > k)
            {
                count[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);

            ++r;
        }
        return ans;
    }
};
