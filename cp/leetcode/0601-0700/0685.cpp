#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    class DSU {
        vector<int> parent;

    public:
        DSU(int n) {
            parent.reserve(n);
            for (int i = 0; i < n; ++i)
                parent.push_back(i);
        }
        int find(int i) {
            if (parent[i] == i)
                return i;
            return parent[i] = find(parent[i]);
        }

        void unionr(int i, int j) { parent[parent[j]] = i; }
    };
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> id(n + 1, 0);
        for (auto& edge : edges)
            id[edge[1]]++;

        DSU ds(n + 1);
        vector<vector<int>> v;
        for (auto& edge : edges) {
            if (id[edge[1]] == 2) {
                v.push_back(edge);
                continue;
            }
            if (ds.find(edge[0]) == ds.find(edge[1])) {
                return edge;
            }
            ds.unionr(edge[0], edge[1]);
        }
        for (auto& edge : v) {
            if (ds.find(edge[0]) == ds.find(edge[1])) {
                return edge;
            }
            ds.unionr(edge[0], edge[1]);
        }
        return {-1, -1};
    }
};