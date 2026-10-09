#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findUpar(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findUpar(parent[node]);
    }
    bool unionbyrank(int u, int v) {
        int pu = findUpar(u);
        int pv = findUpar(v);
        if (pu == pv)
            return false;
        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;
        DisjointSet ds(n);
        for (auto it : connections) {
            int u = it[0];
            int v = it[1];
            ds.unionbyrank(u, v);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (ds.unionbyrank(0, i))
                cnt++;
        }
        return cnt;
    }
};