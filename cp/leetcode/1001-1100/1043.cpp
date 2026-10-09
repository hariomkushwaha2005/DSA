#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int mikasa(int i, int k, vector<int>& arr, vector<int>& dp) {
        int n = arr.size();
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int maxx = arr[i];
        int ans = INT_MIN;
        for (int j = i; j < i + k; j++) {
            if (j == n)
                break;
            maxx = max(maxx, arr[j]);
            ans = max(ans, maxx * (j - i + 1) + mikasa(j + 1, k, arr, dp));
        }
        return dp[i] = ans;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, -1e9);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int maxx = arr[i];
            for (int j = i; j < i + k; j++) {
                if (j == n)
                    break;
                maxx = max(maxx, arr[j]);
                dp[i] = max(dp[i], maxx * (j - i + 1)+dp[j+1]);
            }
        }
        return dp[0];
    }
};