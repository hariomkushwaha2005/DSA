#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int t) {
        vector<vector<int>> adj(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) {
            adj[i][i] = 0;
        }
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]][edges[i][1]] = edges[i][2];
            adj[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        int ans = 0, maxi = 1e9;
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                int cnt = 0;
                for (int j = 0; j < n; j++) {
                    if (adj[i][j] > adj[i][k] + adj[k][j])
                        adj[i][j] = adj[i][k] + adj[k][j];
                    if (adj[i][j] <= t)
                        cnt++;
                }
                if (k == n - 1) {
                    if (cnt <= maxi) {
                        ans = i;
                        maxi = cnt;
                    }
                }
            }
        }
        return ans;
    }
};