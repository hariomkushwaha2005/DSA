#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(2 * n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int t = 2 * n - 1; t >= 0; t--) {
                if (t & 1)
                    dp[t] = max(prices[i] + dp[t + 1], dp[t]);

                else
                    dp[t] = max(-prices[i] + dp[t + 1], dp[t]);
            }
        }
        return dp[0];
    }
};