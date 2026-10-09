#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int help(int i, int j, vector<vector<int>> &matrix,
             vector<vector<int>> &dp)
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        if (i > 0 && matrix[i - 1][j] < matrix[i][j])
            ans = max(ans, help(i - 1, j, matrix, dp));
        if (j > 0 && matrix[i][j - 1] < matrix[i][j])
            ans = max(ans, help(i, j - 1, matrix, dp));
        if (i < matrix.size() - 1 && matrix[i + 1][j] < matrix[i][j])
            ans = max(ans, help(i + 1, j, matrix, dp));
        if (j < matrix[0].size() - 1 && matrix[i][j + 1] < matrix[i][j])
            ans = max(ans, help(i, j + 1, matrix, dp));

        return dp[i][j] = 1 + ans;
    }
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (dp[i][j] == -1)
                {
                    help(i, j, matrix, dp);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};