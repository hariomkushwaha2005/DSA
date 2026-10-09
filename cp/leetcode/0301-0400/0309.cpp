#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // int mikasa(int i, int buy, vector<int>& prices, vector<vector<int>>& dp)
    // {
    //     if (i >= prices.size())
    //         return 0;
    //     if (dp[i][buy] != -1)
    //         return dp[i][buy];
    //     int profit = 0;
    //     if (buy == 0)
    //         profit = max(mikasa(i + 1, 1, prices, dp) - prices[i],
    //                      mikasa(i + 1, 0, prices, dp));
    //     else
    //         profit = max(mikasa(i + 2, 0, prices, dp) + prices[i],
    //                      mikasa(i + 1, 1, prices, dp));
    //     return dp[i][buy] = profit;
    // }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        int buy = 0, sell = 0, last = 0;
        for (int i = n - 1; i >= 0; i--) {
            int x = buy;
            buy = max(sell - prices[i], buy);
            sell = max(last + prices[i], sell);
            last = x;
        }
        return buy;
    }
};