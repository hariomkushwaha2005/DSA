#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < times.size(); i++)
        {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> mint(n + 1, 1e9);
        int delay = 0;
        mint[k] = 0;
        pq.push({0, k});
        while (!pq.empty())
        {
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (time > mint[node])
                continue;
            for (auto &it : adj[node])
            {
                int next = it.first;
                int wait = it.second;
                if (mint[next] > time + wait)
                {
                    mint[next] = time + wait;
                    pq.push({mint[next], next});
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            delay = max(delay, mint[i]);
        }
        if (delay == 1e9)
            return -1;
        return delay;
    }
};