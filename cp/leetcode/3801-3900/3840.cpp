#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long cash(int l, int r, vector<int>& nums, vector<long long>& dp) {
        if (l > r)
            return 0;

        if (dp[l] != -1)
            return dp[l];

        long long ans = nums[l] + cash(l + 2, r, nums, dp);
        ans = max(ans, cash(l + 1, r, nums, dp));

        return dp[l] = ans;
    }

    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        int l = 0;
        long long ans = 0;

        while (l < n) {
            int r = l + 1;
            while (r < n && colors[l] == colors[r])
                r++;

            if (r > l + 1) {
                vector<long long> dp(n, -1);
                ans += cash(l, r - 1, nums, dp);
            } else {
                ans += nums[l];
            }

            l = r;
        }

        return ans;
    }
};