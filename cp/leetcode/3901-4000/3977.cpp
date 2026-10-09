#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> minTimeMaxPower(int n, const vector<vector<int>> &edges, int power, const vector<int> &cost, int source, int target)
    {
        int ne = edges.size();
        vector<array<int, 3>> adj(ne);
        vector<int> head(n, -1);
        for (int i = 0; i < ne; i++)
        {
            adj[i] = {edges[i][1], edges[i][2], head[edges[i][0]]};
            head[edges[i][0]] = i;
        }
        long long INF = 1e18;
        vector<long long> dp((power + 1) * n, INF);
        dp[source] = 0;
        int poff = 0;
        for (int p = 0; p <= power; ++p, poff += n)
        {
            for (int u = 0; u < n; ++u)
            {
                int nextP = p + cost[u];
                long long curTime = dp[poff + u];
                if (curTime == INF || nextP > power)
                    continue;
                int npoff = nextP * n;
                for (int edge = head[u]; edge != -1; edge = adj[edge][2])
                {
                    int v = adj[edge][0];
                    long long newTime = curTime + adj[edge][1];
                    if (dp[npoff + v] > newTime)
                    {
                        dp[npoff + v] = newTime;
                    }
                }
            }
        }
        long long ans = INF;
        int finp = -1;
        poff = 0;
        for (int p = 0; p <= power; ++p, poff += n)
        {
            long long time = dp[poff + target];
            if (ans > time)
            {
                ans = time;
                finp = p;
            }
        }
        if (ans == INF)
            return {-1, -1};
        return {ans, power - finp};
    }
};