#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (auto& it : grid) {
            sort(it.begin(), it.end());
        }
        int ind = m - 1;
        while (ind >= 0) {
            int maxx = 0;
            for (int i = 0; i < n; i++) {
                maxx = max(maxx, grid[i][ind]);
            }
            ind--;
            ans += maxx;
        }
        return ans;
    }
};