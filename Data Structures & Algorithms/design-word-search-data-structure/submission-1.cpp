class WordDictionary {
    struct TrieNode
    {
        vector<TrieNode*> children;
        bool endOfWord;

        TrieNode()
            : children(26, nullptr)
            , endOfWord(false) {}
    };

    TrieNode* root;

    bool dfs(const string& word, int j, TrieNode* root)
    {
        TrieNode* cur = root;
        for (int i = j; i < word.size(); ++i)
        {
            char c = word[i];
            if (c == '.')
            {
                for (TrieNode* child : cur->children)
                {
                    if (child && dfs(word, i + 1, child))
                    {
                        return true;
                    }
                }
                return false;
            }
            else
            {
                int idx = c - 'a';
                if (cur->children[idx] == nullptr)
                    return false;
                cur = cur->children[idx];
            }
        }
        return cur->endOfWord;
    }
public:
    WordDictionary() : root(new TrieNode()) {}
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (auto c : word)
        {
            int i = c - 'a';
            if (cur->children[i] == nullptr)
            {
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
