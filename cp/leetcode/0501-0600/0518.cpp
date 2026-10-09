#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ways(int i, int k, vector<int>& coins, vector<vector<int>>& dp) {
        int n = coins.size();
        if (k == 0)
            return 1;
        if (i == n || k < 0)
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];
        int ans = ways(i, k - coins[i], coins, dp);
        ans += ways(i + 1, k, coins, dp);
        return dp[i][k] = ans;
    }
    int change(int k, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<unsigned int>> dp(n, vector<unsigned int>(k + 1, 0));
        vector<unsigned int> prev(k + 1, 0);
        vector<unsigned int> cur(k + 1, 0);
        cur[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j >= coins[i])
                    cur[j] += cur[j - coins[i]];
            }
        }
        return cur[k];
    }
};