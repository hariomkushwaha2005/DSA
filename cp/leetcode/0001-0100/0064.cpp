#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int path(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i == 0 && j == 0)
            return grid[0][0];
        if (dp[i][j] != -1)
            return dp[i][j];
        int a = INT_MAX, b = INT_MAX;
        if (i > 0)
            a = path(i - 1, j, grid, dp);
        if (j > 0)
            b = path(i, j - 1, grid, dp);
        return dp[i][j] = (grid[i][j] + min(a, b));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        vector<int> prev(m);
        for (int i = 0; i < n; i++) {
            vector<int> temp(m);
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    temp[0] = grid[0][0];
                    continue;
                }
                int a = INT_MAX, b = INT_MAX;
                if (i > 0)
                    a = prev[j];
                if (j > 0)
                    b = temp[j - 1];
                temp[j] = (grid[i][j] + min(a, b));
            }
            prev=temp;
        }
        return prev[m-1];
    }
};