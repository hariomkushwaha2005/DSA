#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // int mikasa(int i, int t, vector<int>& prices, vector<vector<int>>& dp) {
    //     int n = prices.size();
    //     int k = dp[0].size();
    //     if (i == n || t == k)
    //         return 0;
    //     if (dp[i][t] != -1)
    //         return dp[i][t];
    //     int profit = 0;
    //     if (t & 1) {
    //         profit = max(prices[i] + mikasa(i + 1, t + 1, prices, dp),
    //                      mikasa(i + 1, t, prices, dp));
    //     } else {
    //         profit = max(-prices[i] + mikasa(i + 1, t + 1, prices, dp),
    //                      mikasa(i + 1, t, prices, dp));
    //     }
    //     return dp[i][t] = profit;
    // }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
        vector<int> dp(2 * k + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int t = 2 * k - 1; t >= 0; t--) {
                if (t & 1)
                    dp[t] = max(prices[i] + dp[t + 1], dp[t]);

                else
                    dp[t] = max(-prices[i] + dp[t + 1], dp[t]);
            }
        }
        return dp[0];
    }
};