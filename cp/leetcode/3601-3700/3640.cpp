#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long inf = -1e18;
    long long maxSumTrionic(vector<int> &nums)
    {
        int n = nums.size();
        long long dp[3] = {inf, inf, inf};
        long long ans = inf;
        for (int i = 1; i < n; ++i)
        {
            long long cur[3] = {inf, inf, inf};
            if (nums[i] > nums[i - 1])
            {
                cur[0] = nums[i] + max(dp[0], 1LL * nums[i - 1]);
                cur[2] = nums[i] + max(dp[2], dp[1]);
                ans = max(ans, cur[2]);
            }
            else if (nums[i] < nums[i - 1])
                cur[1] = nums[i] + max(dp[1], dp[0]);
            dp[0] = cur[0];
            dp[1] = cur[1];
            dp[2] = cur[2];
        }
        return ans;
    }
};