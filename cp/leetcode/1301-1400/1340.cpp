#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int mikasa(int ind, int d, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();
        int ans = 0;
        if (dp[ind] != -1)
            return dp[ind];
        for (int i = ind + 1; i < n && i <= ind + d; i++) {
            if (nums[i] >= nums[ind])
                break;
            ans = max(ans, mikasa(i, d, nums, dp) + 1);
        }
        for (int i = ind - 1; i >= 0 && i >= ind - d; i--) {
            if (nums[i] >= nums[ind])
                break;
            ans = max(ans, mikasa(i, d, nums, dp) + 1);
        }
        return dp[ind] = ans;
    };

public:
    int maxJumps(vector<int>& nums, int d) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == -1)
                mikasa(i, d, nums, dp);
            ans = max(ans, dp[i]);
        }
        return ans + 1;
    }
};