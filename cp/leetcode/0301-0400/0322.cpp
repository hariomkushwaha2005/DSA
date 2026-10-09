#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gojo(int i, int k, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        if (k == 0)
            return 0;
        if (i >= n || k < 0)
            return 1e9;
        if (dp[i][k] != -1)
            return dp[i][k];
        int a = gojo(i + 1, k, nums, dp);
        int b = 1 + gojo(i + 1, k - nums[i], nums, dp);
        int c = 1 + gojo(i, k - nums[i], nums, dp);
        return dp[i][k] = min({a, b, c});
    }
    int coinChange(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, 1e9));
        vector<int> prev(k+1,1e9);
        vector<int> curr(k+1,1e9);
        for (int i = 0; i < n; i++) {
            curr[0] = 0;
            if (nums[i] <= k)
                curr[nums[i]] = 1;
            for (int j = 1; j <= k; j++) {
                int a = 1e9;
                if (i > 0)
                    a = prev[j];
                int c = 1e9;
                if (nums[i] <= j)
                    c = 1 + curr[j - nums[i]];
                curr[j]=min(a,c);
            }
            prev=curr;
        }
        return prev[k]==1e9?-1:prev[k];
    }
};