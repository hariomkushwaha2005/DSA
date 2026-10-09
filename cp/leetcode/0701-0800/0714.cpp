#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // int mikasa(int i, int buy, int fee, vector<int>& prices,
    //            vector<vector<int>>& dp) {
    //     if (i >= prices.size())
    //         return 0;
    //     if (dp[i][buy] != -1)
    //         return dp[i][buy];
    //     int profit = 0;
    //     if (buy == 0)
    //         profit = max(mikasa(i + 1, 1, fee, prices, dp) - prices[i] - fee,
    //                      mikasa(i + 1, 0, fee, prices, dp));
    //     else
    //         profit = max(mikasa(i + 1, 0, fee, prices, dp) + prices[i],
    //                      mikasa(i + 1, 1, fee, prices, dp));
    //     return dp[i][buy] = profit;
    // }

public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int profit = 0, sell = prices[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            if (prices[i] + fee < sell) {
                profit += sell - prices[i] - fee;
                sell = prices[i] + fee;
            }
            sell = max(sell, prices[i]);
        }
        return profit;
    }
};
