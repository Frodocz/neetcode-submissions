class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.size(), l = 0, r = 0, ans = 0;
        while (r < n)
        {
            char c = s[r];
            // enter window
            if (mp.find(c) != mp.end())
            {
                l = max(mp[c] + 1, l);
            }
            mp[c] = r;
            // update
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};
