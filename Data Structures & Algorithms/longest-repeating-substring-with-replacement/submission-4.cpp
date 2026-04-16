class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> chars(s.begin(), s.end());
        int n = s.size(), ans = 0;

        for (char c : chars)
        {
            int count = 0, l = 0, r = 0;
            while (r < n)
            {
                if (s[r] == c)
                    count++;
                
                while ((r - l + 1) - count > k)
                {
                    if (s[l] == c)
                        count--;
                    l++;
                }

                ans = max(ans, r - l + 1);
                r++;
            }
        }
        return ans;
    }
};
