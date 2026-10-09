#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // int lcs(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
    //     if (i < 0 || j < 0)
    //         return 0;
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     int ans = 0;
    //     if (s1[i] == s2[j])
    //         ans = 1 + lcs(i - 1, j - 1, s1, s2, dp);
    //     else {
    //         int a = lcs(i - 1, j, s1, s2, dp);
    //         int b = lcs(i, j - 1, s1, s2, dp);
    //         ans = max(a, b);
    //     }
    //     return dp[i][j] = ans;
    // }

public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        string s;
        int i = n;
        int j = m;
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                s += s1[i - 1];
                i--, j--;
            } else if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
        reverse(s.begin(),s.end());
        return s.size();
    }
};