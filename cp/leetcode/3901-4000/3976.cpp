#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxSubarraySum(const vector<int> &nums, int k)
    {
        const int n = nums.size();
        const long long INF = -1e18;

        long long ans = INF;
        long long dp0 = INF, dp1 = INF, dp2 = INF, dp3 = INF, dp4 = INF;

        const int *ptr = nums.data();

        for (int i = 0; i < n; i++)
        {
            long long val = ptr[i];
            long long mul = val * k;
            long long div = val / k;

            long long cur0 = max(dp0, 0LL) + val;
            long long cur1 = max(dp0, max(dp1, 0LL)) + mul;
            long long cur2 = max(dp1, dp2) + val;
            long long cur3 = max(dp0, max(dp3, 0LL)) + div;
            long long cur4 = max(dp3, dp4) + val;

            dp0 = cur0;
            dp1 = cur1;
            dp2 = cur2;
            dp3 = cur3;
            dp4 = cur4;
            ans = max(ans, max(max(dp1, dp2), max(dp3, dp4)));
        }
        return ans;
    }
};