#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    //     bool mikasa(int i, int j, string& s, string& p, vector<vector<int>>&
    //     dp) {
    //         if (j < 0) {
    //             if (i < 0)
    //                 return true;
    //             return false;
    //         }
    //         if (i < 0) {
    //             for (int k = j; k >= 0; k--) {
    //                 if (p[k] != '*')
    //                     return false;
    //             }
    //             return true;
    //         }
    //         if (dp[i][j] != -1)
    //             return dp[i][j];

    //         bool ans = false;
    //         if (p[j] == '*') {
    //             ans = ans | mikasa(i - 1, j, s, p, dp);
    //             ans = ans | mikasa(i, j - 1, s, p, dp);
    //         } else if (s[i] == p[j] || p[j] == '?')
    //             ans = ans | mikasa(i - 1, j - 1, s, p, dp);

    //         return dp[i][j] = ans;
    //     }

public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        // vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        vector<bool> dp(m + 1, 0), cur(m + 1, 0);
        dp[0] = true;
        for (int i = 1; i <= m; i++) {
            if (p[i - 1] == '*')
                dp[i] = true;
            else
                break;
        }
        for (int i = 1; i <= n; i++) {
            cur[0] = 0;
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == '*')
                    cur[j] = dp[j] | cur[j - 1];

                else if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    cur[j] = dp[j - 1];
                } else
                    cur[j] = false;
            }
            swap(cur, dp);
        }
        return dp[m];
    }
};