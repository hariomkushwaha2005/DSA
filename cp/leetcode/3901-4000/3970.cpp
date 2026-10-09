#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPath(int n, const vector<vector<int>> &edges,
                     const string &labels, int k)
    {

        struct Edge
        {
            int to;
            int weight;
            int next;
        };

        struct State
        {
            int val, con, u;
            bool operator>(const State &other) const { return val > other.val; }
        };

        int ne = edges.size();
        vector<int> head(n, -1);

        vector<Edge> adj(ne);
        vector<int> mincon(n, k + 1);

        for (int i = 0; i < ne; ++i)
        {
            adj[i] = {edges[i][1], edges[i][2], head[edges[i][0]]};
            head[edges[i][0]] = i;
        }

        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push({0, 1, 0});

        while (!pq.empty())
        {
            State h = pq.top();
            int val = h.val;
            int con = h.con;
            int u = h.u;
            pq.pop();
            if (u == n - 1)
                return val;
            if (mincon[u] <= con)
                continue;
            mincon[u] = con;
            for (int edge = head[u]; edge != -1; edge = adj[edge].next)
            {
                int next = labels[u] == labels[adj[edge].to] ? con + 1 : 1;
                if (next <= k)
                {
                    if (next < mincon[adj[edge].to])
                        pq.push({val + adj[edge].weight, next, adj[edge].to});
                }
            }
        }
        return -1;
    }
};