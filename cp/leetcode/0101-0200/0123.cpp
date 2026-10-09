#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1 = -1e9, buy2 = -1e9, sell1 = -1e9, sell2 = -1e9;
        for (int i = 0; i < n; i++) {
            buy1 = max(buy1, 0 - prices[i]);
            sell1 = max(sell1, prices[i] + buy1);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
};