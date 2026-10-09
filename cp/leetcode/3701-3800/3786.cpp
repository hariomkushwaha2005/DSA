#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    long long interactionCosts(int n, vector<vector<int>>& edges,
                               vector<int>& group) {
        vector<vector<int>> adj(n);
        for (auto& it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> grcnt(21, 0);
        for (int i = 0; i < n; i++) {
            grcnt[group[i]]++;
        }
        ll ans = 0;
        vector<vector<int>> subgr(n, vector<int>(21, 0));
        auto dfs = [&](auto& self, int u, int p) -> void {
            subgr[u][group[u]]++;
            for (auto& v : adj[u]) {
                if (v == p)
                    continue;
                self(self, v, u);
                for (int i = 1; i <= 20; i++) {
                    subgr[u][i] += subgr[v][i];
                    ll x1 = subgr[v][i];
                    ll x2 = grcnt[i] - x1;
                    ans += x1 * x2;
                }
            }
        };
        dfs(dfs, 0, -1);
        return ans;
    }
};