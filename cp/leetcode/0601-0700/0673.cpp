#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), prev(n, 1);
        int maxi = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        cnt = 0;
                    }
                    if (dp[i] == dp[j] + 1) {
                        cnt += prev[j];
                    }
                }
            }
            if (maxi < dp[i])
                maxi = dp[i];
            prev[i] = cnt;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi)
                ans += prev[i];
        }
        return ans;
    }
};