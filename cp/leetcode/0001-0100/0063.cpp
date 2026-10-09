#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kaguya(vector<vector<int>>& mat, int i, int j,
               vector<vector<int>>& dp) {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (mat[i][j] == 1)
            return dp[i][j] = 0;
        if (i == 0 && j == 0)
            return dp[0][0] = 1;
        int up = kaguya(mat, i - 1, j, dp);
        int left = kaguya(mat, i, j - 1, dp);
        return dp[i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        if (mat[0][0] == 1 || mat[n - 1][m - 1] == 1)
            return 0;
        vector<int> prev(m,0);
        for (int i = 0; i < n; i++) {
            vector<int> temp(m,0);
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    temp[j] = 1;
                    continue;
                }
                int up = 0, left = 0;
                if (i > 0 && mat[i][j] != 1)
                    up = prev[j];
                if (j > 0 && mat[i][j] != 1)
                    left = temp[j - 1];
                temp[j] = up + left;
            }
            prev=temp;
        }
        return prev[m - 1];
    }
};