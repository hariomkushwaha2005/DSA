#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ways(int i, int k, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        if (k < 0)
            return 0;
        if (i == n)
            return (k == 0);
        if (dp[i][k] != -1)
            return dp[i][k];
        int a = ways(i + 1, k, nums, dp);
        int b = ways(i + 1, k - nums[i], nums, dp);
        return dp[i][k] = a + b;
    }
    int findTargetSumWays(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += abs(nums[i]);
        sum -= k;
        if (sum < 0 || (sum) & 1)
            return 0;
        sum >>= 1;
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
        vector<int> prev(sum+1,0);
        prev[0]++;
        if (sum >= nums[0])
            prev[nums[0]]++;
        for (int i = 1; i < n; i++) {
            vector<int> curr(sum+1,0);
            for (int j = 0; j <= sum; j++) {
                curr[j] += prev[j];
                if (nums[i] <= j)
                    curr[j] += prev[j - nums[i]];
            }
            prev=curr;
        }
        return prev[sum];
    }
};