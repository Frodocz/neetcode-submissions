class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> cnt;
        int n = s.size(), l = 0, r = 0, ans = 0;
        while (r < n)
        {
            char c = s[r];
            // enter window
            cnt[c]++;

            // check window and dedup
            while (cnt[c] > 1)
            {
                cnt[s[l]]--;
                l++;
            }

            // update
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};
