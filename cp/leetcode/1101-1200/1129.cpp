#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges,
                                         vector<vector<int>> &blueEdges)
    {

        vector<vector<vector<int>>> adj(2, vector<vector<int>>(n));
        for (auto &edge : redEdges)
            adj[0][edge[0]].push_back(edge[1]);
        for (auto &edge : blueEdges)
            adj[1][edge[0]].push_back(edge[1]);

        vector<int> ans(n, -1);
        ans[0] = 0;
        vector<vector<int>> vis(2, vector<int>(n, 0));
        queue<array<int, 3>> q;
        q.push({0, 0, 0});
        q.push({0, 1, 0});

        while (!q.empty())
        {
            int node = q.front()[0], color = !q.front()[1], dist = q.front()[2];
            q.pop();
            for (int v : adj[color][node])
            {
                if (ans[v] == -1 || ans[v] >= dist + 1)
                {
                    ans[v] = dist + 1;
                }
                if (!vis[color][v])
                {
                    vis[color][v] = 1;
                    q.push({v, color, dist + 1});
                }
            }
        }
        return ans;
    }
};
