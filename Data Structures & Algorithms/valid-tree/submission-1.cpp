class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<vector<int>> adjList(n);
        for (auto& e : edges)
        {
            int u = e[0], v = e[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        // a simple dfs/bfs can traverse all nodes 
        // and no cycle => valid tree
        queue<pair<int, int>> q;
        unordered_set<int> visited;
        q.push({0, -1}); // {current node, parent node}
        visited.insert(0);
        while (!q.empty())
        {
            auto [cur, parent] = q.front(); q.pop();
            for (auto nei : adjList[cur])
            {
                if (nei == parent) continue;
                if (visited.contains(nei))
                {
                    return false;
                }
                visited.insert(nei);
                q.push({nei, cur});
            }
        }

        return visited.size() == n;
    }
};
