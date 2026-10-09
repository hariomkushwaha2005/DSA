#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // int mikasa(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     int len = i == 0 ? cuts[j - 1] : cuts[j - 1] - cuts[i - 1];
    //     int ans = INT_MAX;
    //     for (int k = i + 1; k < j; k++) {
    //         ans =
    //             min(ans, len + mikasa(i, k, cuts, dp) + mikasa(k, j, cuts,
    //             dp));
    //     }
    //     return dp[i][j] = ans == INT_MAX ? 0 : ans;
    // }

public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.push_back(n);
        int m = cuts.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = i; j < m; j++) {
                int len = i == 0 ? cuts[j] : cuts[j] - cuts[i - 1];
                int ans = INT_MAX;
                for (int k = i; k < j; k++) {
                    ans = min(ans, len + dp[i][k] + dp[k + 1][j]);
                }
                dp[i][j] = ans == INT_MAX ? 0 : ans;
            }
        }

        return dp[0][m - 1];
    }
};