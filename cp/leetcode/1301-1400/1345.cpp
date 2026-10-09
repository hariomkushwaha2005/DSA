#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        vector<int> dist(n, 1e9);
        dist[0] = 0;

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            if(node == n - 1) return dist[node];

            if (node - 1 >= 0 && dist[node - 1] > dist[node] + 1) {
                dist[node - 1] = dist[node] + 1;
                q.push(node - 1);
            }

            if (node + 1 < n && dist[node + 1] > dist[node] + 1) {
                dist[node + 1] = dist[node] + 1;
                q.push(node + 1);
            }

            for (auto& it : mp[arr[node]]) {
                if (dist[it] > dist[node] + 1) {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
            mp.erase(arr[node]);
        }
        return dist[n - 1];
    }
};