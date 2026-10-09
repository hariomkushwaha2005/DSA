#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, 0);
        vis[start] = 1;
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int node = q.front();
            if (arr[node] == 0)
                return true;
            q.pop();
            if (node + arr[node] < n && !vis[node + arr[node]]) {
                q.push(node + arr[node]);
                vis[node + arr[node]] = 1;
            }
            if (node - arr[node] >= 0 && !vis[node - arr[node]]) {
                q.push(node - arr[node]);
                vis[node - arr[node]] = 1;
            }
        }
        return false;
    }
};