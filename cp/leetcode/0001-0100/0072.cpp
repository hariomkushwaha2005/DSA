#include <bits/stdc++.h>
using namespace std;

class Solution {
    // private:
    //     int mikasa(int i, int j, string& s, string& t, vector<vector<int>>&
    //     dp) {
    //         if (i < 0)
    //             return j + 1;
    //         if (j < 0)
    //             return i + 1;
    //         if (dp[i][j] != -1)
    //             return dp[i][j];
    //         if (s[i] == t[j])
    //             return dp[i][j] = mikasa(i - 1, j - 1, s, t, dp);
    //         int replace = 1 + mikasa(i - 1, j - 1, s, t, dp);
    //         int remove = 1 + mikasa(i - 1, j, s, t, dp);
    //         int add = 1 + mikasa(i, j - 1, s, t, dp);
    //         return dp[i][j] = min({replace, remove, add});
    //     }

public:
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> dp(m + 1, 0), cur(m + 1, 0);
        for (int i = 0; i <= m; i++)
            dp[i] = i;
        for (int i = 1; i <= n; i++) {
            cur[0] = i;
            for (int j = 1; j <= m; j++) {
                cur[j] = dp[j - 1];
                if (s[i - 1] != t[j - 1])
                    cur[j] = min({1 + cur[j], 1 + dp[j], 1 + cur[j - 1]});
            }
            swap(cur, dp);
        }
        return dp[m];
    }
};