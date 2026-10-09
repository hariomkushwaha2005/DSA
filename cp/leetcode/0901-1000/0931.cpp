#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int path(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
    {
        int n = mat.size();
        if (j < 0 || j >= n)
            return INT_MAX;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == n - 1)
            return dp[i][j] = mat[i][j];
        int a = path(i + 1, j - 1, mat, dp);
        int b = path(i + 1, j, mat, dp);
        int c = path(i + 1, j + 1, mat, dp);

        return dp[i][j] = mat[i][j] + min({a, b, c});
    }
    int minFallingPathSum(vector<vector<int>> &mat)
    {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<int> prev(n);
        for (int i = n - 1; i >= 0; i--)
        {
            vector<int> cur(n);
            for (int j = n - 1; j >= 0; j--)
            {
                int a = 0, b = 0, c = 0;
                if (i < n - 1)
                {
                    if (j > 0)
                        a = prev[j - 1];
                    else
                        a = INT_MAX;
                    b = prev[j];
                    if (j < n - 1)
                        c = prev[j + 1];
                    else
                        c = INT_MAX;
                }
                cur[j] = mat[i][j] + min({a, b, c});
            }
            prev = cur;
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, prev[i]);
        }
        return ans;
    }
};