#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lcs(int i, int j, vector<int> &a, vector<int> &b,
            vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = max(lcs(i - 1, j, a, b, dp), lcs(i, j - 1, a, b, dp));
        if (a[i] == b[j])
            ans = max(ans, 1 + lcs(i - 1, j - 1, a, b, dp));

        return dp[i][j] = ans;
    }
    int minimumMountainRemovals(vector<int> &nums)
    {
        vector<int> u = nums;
        sort(u.begin(), u.end());
        auto st = unique(u.begin(), u.end());
        u.erase(st, u.end());

        int n = nums.size();
        int m = u.size();

        vector<vector<int>> dp1(n, vector<int>(m, -1));
        lcs(n - 1, m - 1, nums, u, dp1);

        reverse(nums.begin(), nums.end());

        vector<vector<int>> dp2(n, vector<int>(m, -1));
        lcs(n - 1, m - 1, nums, u, dp2);

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (dp1[i][m - 1] > 1 && dp2[n - 1 - i][m - 1] > 1)
                ans = max(ans, dp1[i][m - 1] + dp2[n - 1 - i][m - 1] - 1);
        }
        return n - ans;
    }
};