#include <bits/stdc++.h>
using namespace std;

class Solution {
    class DSU {
        vector<int> rank;
        vector<int> parent;

    public:
        DSU(int n) {
            rank.reserve(n);
            parent.reserve(n);
            for (int i = 0; i < n; ++i) {
                rank.push_back(1);
                parent.push_back(i);
            }
        }

        int find(int i) {
            if (parent[i] == i)
                return i;
            return parent[i] = find(parent[i]);
        }

        void unionr(int i, int j) {
            int pari = parent[i];
            int parj = parent[j];
            if (rank[pari] >= rank[parj]) {
                parent[parj] = pari;
                rank[pari] += rank[pari] == rank[parj];
            } else {
                parent[pari] = parj;
            }
        }
    };

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU ds(n + 1);
        vector<int> ans;
        for (auto& it : edges) {
            if (ds.find(it[0]) != ds.find(it[1])) {
                ds.unionr(it[0], it[1]);
            } else
                ans = it;
        }
        return ans;
    }
};