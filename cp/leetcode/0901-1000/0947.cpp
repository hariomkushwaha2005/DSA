#include <bits/stdc++.h>
using namespace std;

class DS
{
    vector<int> size, parent;

public:
    DS(int n)
    {
        size.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }
    void uni(int u, int v)
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
            size[pv] += size[pu];
            parent[pu] = pv;
        }
    }
};
class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        DS ds(20002);
        unordered_set<int> st;
        for (auto &it : stones)
        {
            int u = it[0];
            int v = it[1] + 10001;
            ds.uni(u, v);
            st.insert(u);
            st.insert(v);
        }
        int cnt = 0;
        for (auto &it : st)
        {
            if (it == ds.find(it))
                cnt++;
        }
        return n - cnt;
    }
};