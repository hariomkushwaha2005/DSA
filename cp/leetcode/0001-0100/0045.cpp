#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // int mikasa(int i, vector<int>& nums, vector<int>& dp) {
    //     if (i >= nums.size() - 1)
    //         return 0;
    //     if (dp[i] != -1)
    //         return dp[i];
    //     int x = nums[i];
    //     int ans = 1e9;
    //     while (x > 0) {
    //         ans = min(ans, mikasa(i + x, nums, dp));
    //         x--;
    //     }
    //     return dp[i] = 1 + ans;
    // }

public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1e9);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j < n)
                    dp[i + j] = min(dp[i + j], 1 + dp[i]);
                else
                    break;
            }
        }
        return dp[n-1];
    }
};