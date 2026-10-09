#include <bits/stdc++.h>
using namespace std;
class DS
{
public:
    vector<int> rank, parent;
    DS(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }
    void unite(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

        if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else if (rank[pv] > rank[pu])
            parent[pu] = pv;
        else
        {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};
class Solution
{
private:
    bool isValid(int i, int j, int n)
    {
        return (i < n && i >= 0 && j < n && j >= 0);
    }

public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DS ds(n * n);
        int dst = (n - 1) * n + n - 1;
        vector<pair<int, int>> cell(n * n);
        vector<int> di = {-1, 0, 1, 0};
        vector<int> dj = {0, 1, 0, -1};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cell[grid[i][j]] = {i, j};
            }
        }
        int wt = 0;
        for (; wt < n * n; wt++)
        {
            int i = cell[wt].first;
            int j = cell[wt].second;
            int node = i * n + j;
            for (int k = 0; k < 4; k++)
            {
                int ni = i + di[k];
                int nj = j + dj[k];
                if (isValid(ni, nj, n) && grid[ni][nj] <= wt)
                {
                    int nnode = ni * n + nj;
                    ds.unite(node, nnode);
                }
            }
            if (ds.find(0) == ds.find(dst))
                break;
        }
        return wt;
    }
};