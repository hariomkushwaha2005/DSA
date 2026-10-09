#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int time = 1;
    void dfs(int node, int parent, vector<int> &tin, vector<int> &low,
             vector<vector<int>> &adj, vector<vector<int>> &ans)
    {
        tin[node] = low[node] = time;
        time++;
        for (auto &it : adj[node])
        {
            if (it == parent)
                continue;
            if (tin[it] == 0)
            {
                dfs(it, node, tin, low, adj, ans);
                low[node] = min(low[node], low[it]);
                if (tin[node] < low[it])
                    ans.push_back({node, it});
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>> &connections)
    {
        vector<vector<int>> adj(n);
        for (auto &it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>> ans;
        vector<int> tin(n, 0);
        vector<int> low(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (tin[i] == 0)
            {
                dfs(i, -1, tin, low, adj, ans);
            }
        }
        return ans;
    }
};