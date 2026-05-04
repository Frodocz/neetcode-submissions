class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());

        if (!words.contains(endWord) || beginWord == endWord) return 0;

        int res = 0;
        queue<string> q;
        q.push(beginWord);

        while (!q.empty())
        {
            res++;
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                string node = q.front();
                q.pop();
                if (node == endWord) return res;

                for (int j = 0; j < node.length(); ++j)
                {
                    char original = node[j];
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        if (c == original) continue;
                        node[j] = c;
                        if (words.contains(node))
                        {
                            q.push(node);
                            words.erase(node);
                        }
                    }
                    node[j] = original;
                }
            }
        }
        return 0;
    }
};
