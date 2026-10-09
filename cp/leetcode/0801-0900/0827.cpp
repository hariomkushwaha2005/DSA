#include <bits/stdc++.h>
using namespace std;

class DS
{
    vector<int> size, parent;

public:
    DS(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }
    void ubr(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return;
        if (size[pu] > size[pv])
        {
            size[pu] += size[pv];
            parent[pv] = pu;
        }
        else
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
    int sizee(int node) { return size[find(node)]; }
};
class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DS ds(n * n);
        vector<int> di = {-1, 0, 1, 0};
        vector<int> dj = {0, 1, 0, -1};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int node = i * n + j;
                    for (int k = 0; k < 4; k++)
                    {
                        int ni = i + di[k];
                        int nj = j + dj[k];
                        if (ni < n && ni >= 0 && nj >= 0 && nj < n &&
                            grid[ni][nj] == 1)
                        {
                            int nnode = ni * n + nj;
                            ds.ubr(node, nnode);
                        }
                    }
                }
            }
        }
        int ans = 0;
        int zero = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    int cnt = 0;
                    zero++;
                    unordered_set<int> st;
                    for (int k = 0; k < 4; k++)
                    {
                        int ni = i + di[k];
                        int nj = j + dj[k];
                        if (ni < n && ni >= 0 && nj >= 0 && nj < n &&
                            grid[ni][nj] == 1)
                        {
                            int nnode = ni * n + nj;
                            if (!st.count(ds.find(nnode)))
                            {
                                cnt += ds.sizee(nnode);
                                st.insert(ds.find(nnode));
                            }
                        }
                    }
                    ans = max(ans, cnt);
                }
            }
        }
        if (zero == 0)
            return n * n;
        return ans + 1;
    }
};