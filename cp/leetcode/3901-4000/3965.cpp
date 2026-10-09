#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int to;
    int next;
};
class Solution
{
private:
    long long mikasa(int i, const Edge *adj, const int *head,
                     const int *baseTime)
    {
        if (head[i] == -1)
            return baseTime[i];
        long long maxx = LLONG_MIN, minn = LLONG_MAX;
        for (int edge = head[i]; edge != -1; edge = adj[edge].next)
        {

            long long child = mikasa(adj[edge].to, adj, head, baseTime);

            if (child > maxx)
                maxx = child;
            if (child < minn)
                minn = child;
        }
        return (maxx << 1) - minn + baseTime[i];
    }

public:
    long long finishTime(int n, vector<vector<int>> &edges,
                         vector<int> &baseTime)
    {
        int ne = edges.size();
        vector<int> head(n, -1);
        int *h = head.data();
        vector<Edge> adj(ne);
        Edge *a = adj.data();
        for (int i = 0; i < ne; ++i)
        {
            const auto &e = edges[i];
            a[i] = {e[1], h[e[0]]};
            h[e[0]] = i;
        }
        return mikasa(0, a, h, baseTime.data());
    }
};