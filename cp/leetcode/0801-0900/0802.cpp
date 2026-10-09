#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> degree(n, 0);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            degree[i] = graph[i].size();
            for (auto it : graph[i]) {
                adj[it].push_back(i);
            }
        }
        vector<int> ans;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto it : adj[node]) {
                degree[it]--;
                if (degree[it] == 0)
                    q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};