#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int st = prices[0];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, prices[i] - st);
            st = min(st, prices[i]);
        }
        return ans;
    }
};