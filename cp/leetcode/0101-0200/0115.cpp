#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // int ds(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
    //     if (j < 0)
    //         return 1;
    //     if (i < 0)
    //         return 0;
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     int ans = ds(i - 1, j, s, t, dp);
    //     if (s[i] == t[j])
    //         ans += ds(i - 1, j - 1, s, t, dp);
    //     return dp[i][j] = ans;
    // }
public:
    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        // vector<vector<unsigned int>> dp(n + 1, vector<unsigned int>(m + 1,
        // 0));
        vector<unsigned int> cur(m + 1, 0);
        cur[0] = 1;
        // for (int i = 0; i <= n; i++) {
        //     dp[i][0] = 1;
        // }
        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j > 0; j--)
            {
                // dp[i][j] = dp[i - 1][j];
                // if (s[i - 1] == t[j - 1])
                //     dp[i][j] += dp[i - 1][j - 1];

                if (s[i - 1] == t[j - 1])
                    cur[j] += cur[j - 1];
            }
        }
        return cur[m];
    }
};