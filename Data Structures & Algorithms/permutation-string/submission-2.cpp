class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m > n) return false;

        vector<int> cnt1(26);
        vector<int> cnt2(26);

        for (int i = 0; i < m; ++i)
        {
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }
        int matched = 0;
        for (int i = 0; i < 26; ++i)
        {
            if (cnt1[i] == cnt2[i])
                ++matched;
        }

        int l = 0, r = m;
        while (r < n)
        {
            if (matched == 26) return true;

            int index = s2[r] - 'a';
            cnt2[index]++;
            if (cnt1[index] == cnt2[index])
                matched++;
            else if (cnt1[index] + 1 == cnt2[index])
                matched--;
            
            index = s2[l] - 'a';
            cnt2[index]--;
            if (cnt1[index] == cnt2[index])
                matched++;
            else if (cnt1[index] - 1 == cnt2[index])
                matched--;
            
            l++;
            r++;
        }
        return matched == 26;
    }
};
