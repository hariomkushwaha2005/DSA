#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int mod = 1e9 + 7;

public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<long long, long long>>> adj(n);
        for (int i = 0; i < roads.size(); i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            long long t = roads[i][2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
        priority_queue<pair<long long, long long>,
                       vector<pair<long long, long long>>, greater<>>
            pq;
        vector<long long> dist(n, LLONG_MAX);
        pq.push({0, 0});
        dist[0] = 0;
        vector<long long> ways(n, 0);
        ways[0] = 1;
        while (!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (d > dist[node])
                continue;
            for (auto &it : adj[node])
            {
                int next = it.first;
                int cost = it.second;
                if (dist[next] == cost + d)
                {
                    ways[next] += ways[node];
                    ways[next] %= mod;
                }
                if (dist[next] > cost + d)
                {
                    dist[next] = cost + d;
                    ways[next] = ways[node];
                    pq.push({dist[next], next});
                }
            }
        }
        return ways[n - 1];
    }
};