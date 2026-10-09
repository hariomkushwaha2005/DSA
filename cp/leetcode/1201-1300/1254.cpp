#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (i < 0 || j < 0 || i == n || j == m)
            return false;
        if (grid[i][j] == 1 || grid[i][j] == 2)
            return true;
        grid[i][j] = 2;
        int ans = dfs(i + 1, j, grid);
        ans &= dfs(i, j + 1, grid);
        ans &= dfs(i - 1, j, grid);
        ans &= dfs(i, j - 1, grid);
        return ans;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0)
                    ans += dfs(i, j, grid);
            }
        }
        return ans;
    }
};