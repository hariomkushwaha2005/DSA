#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        queue<int> q;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                q.push(i);
                vis[i] = 1;
                while (!q.empty())
                {
                    int size = q.size();
                    while (size--)
                    {
                        int x = q.front();
                        q.pop();
                        for (auto it : graph[x])
                        {
                            if (vis[it] == vis[x])
                                return false;
                            else if (vis[it] == 0)
                            {
                                vis[it] = vis[x] == 1 ? 2 : 1;
                                q.push(it);
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};