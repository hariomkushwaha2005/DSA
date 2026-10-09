#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
            return 0;
        sum >>= 1;
        vector<int> cur(sum + 1, 0), dp(sum + 1, 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= sum; ++j) {
                cur[j] = dp[j];
                if (nums[i - 1] <= j) {
                    cur[j] = max(cur[j], nums[i - 1] + dp[j - nums[i - 1]]);
                }
            }
            swap(cur, dp);
        }
        return dp[sum] == sum;
    }
};