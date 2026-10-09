#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), prev(n, -1);
        int maxx = 0, maxi = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = 1 + dp[j];
                    prev[i] = j;
                }
            }
            if (dp[i] > maxx) {
                maxx = dp[i];
                maxi = i;
            }
        }
        vector<int> ans;
        while (maxi > -1) {
            ans.push_back(nums[maxi]);
            maxi = prev[maxi];
        }
        return ans;
    }
};