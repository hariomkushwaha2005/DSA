#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int help(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 2 ||
            grid[i][j] == 0)
            return 0;

        int ans = 1;
        grid[i][j] = 2;
        ans += help(i - 1, j, grid);
        ans += help(i + 1, j, grid);
        ans += help(i, j - 1, grid);
        ans += help(i, j + 1, grid);

        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ans = max(ans, help(i, j, grid));
                }
            }
        }
        return ans;
    }
};