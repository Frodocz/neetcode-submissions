class Solution {
    vector<vector<int>> adjList;
    vector<int> visited;
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        adjList.resize(n);
        visited.resize(n);
        int ans = 0;
        for (auto& edge : edges)
        {
            int a = edge[0], b = edge[1];
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }

        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                ans++;
                dfs(adjList, i);
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>> adjList, int start)
    {
        if (visited[start]) return;
        visited[start] = 1;
        for (auto nei : adjList[start])
        {
            if (!visited[nei])
            {
                dfs(adjList, nei);
            }
        }
    }
};
