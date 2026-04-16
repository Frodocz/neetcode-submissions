class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> cntT, window;
        for (auto c : t)
        {
            cntT[c]++;
        }

        int have = 0, need = cntT.size();
        pair<int, int> res = {-1, -1};
        int ansLen = INT_MAX;
        int l = 0, r = 0, n = s.size();
        while (r < n)
        {
            char c = s[r];
            window[c]++;
            
            if (cntT.contains(c) && window[c] == cntT[c])
            {
                have++;
            }

            while (have == need)
            {
                int curLen = r - l + 1;
                if (curLen < ansLen)
                {
                    ansLen = curLen;
                    res = {l, r};
                }
                char out = s[l];
                window[out]--;
                if (cntT.contains(out) && window[out] < cntT[out])
                {
                    have--;
                }
                l++;
            }
            r++;
        }

        return ansLen == INT_MAX ? "" : s.substr(res.first, ansLen);
    }
};
