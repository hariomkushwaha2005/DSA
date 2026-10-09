#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                          int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < flights.size(); i++)
        {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        queue<pair<int, int>> q;
        q.push({src, 0});
        vector<int> cost(n, 1e9);
        cost[src] = 0;
        int level = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int node = q.front().first;
                int cos = q.front().second;
                q.pop();
                for (auto &it : adj[node])
                {
                    int next = it.first;
                    int price = it.second;
                    if (cost[next] > cos + price)
                    {
                        cost[next] = cos + price;
                        q.push({next, cos + price});
                    }
                }
            }
            if (level == k)
                break;
            level++;
        }
        return cost[dst] == 1e9 ? -1 : cost[dst];
    }
};