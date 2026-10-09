#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int path(int i, int j, int k, vector<vector<int>> &grid,
             vector<vector<vector<int>>> &dp)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (j < 0 || j > m - 1 || k < 0 || k > m - 1)
            return 0;
        if (i >= n)
            return 0;
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        int a = path(i + 1, j - 1, k, grid, dp);
        int b = path(i + 1, j, k, grid, dp);
        int c = path(i + 1, j + 1, k, grid, dp);
        int d = path(i + 1, j - 1, k - 1, grid, dp);
        int e = path(i + 1, j, k - 1, grid, dp);
        int f = path(i + 1, j + 1, k - 1, grid, dp);
        int g = path(i + 1, j - 1, k + 1, grid, dp);
        int h = path(i + 1, j, k + 1, grid, dp);
        int l = path(i + 1, j + 1, k + 1, grid, dp);

        int ans = max({a, b, c, d, e, f, g, h, l});
        ans += grid[i][j];
        if (j != k)
            ans += grid[i][k];
        return dp[i][j][k] = ans;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> prev(m, vector<int>(m));
        for (int i = n - 1; i >= 0; i--)
        {
            vector<vector<int>> temp(m, vector<int>(m));
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    int ans = 0;
                    if (i < n - 1)
                    {
                        for (int l = -1; l <= 1; l++)
                        {
                            for (int o = -1; o <= 1; o++)
                            {
                                if (j + l < 0 || k + o < 0 || j + l == m ||
                                    k + o == m)
                                    continue;
                                ans = max(ans, prev[j + l][k + o]);
                            }
                        }
                    }
                    ans += grid[i][j];
                    if (j != k)
                        ans += grid[i][k];
                    temp[j][k] = ans;
                }
            }
            prev = temp;
        }
        return prev[0][m - 1];
    }
};