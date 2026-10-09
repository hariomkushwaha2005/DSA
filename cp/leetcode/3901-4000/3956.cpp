#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long INF = 1e18;
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();
        vector<long long> presum(n + 1);
        presum[0] = 0;
        for (int i = 0; i < n; ++i) {
            presum[i + 1] = presum[i] + nums[i];
        }
        vector<long long> dp(n + 1, 0);
        vector<long long> cur(n + 1, 0);
        int dq[100005];
        for (int i = m - 1; i >= 0; --i) {
            if (i == 0)
                cur[n] = -INF;
            int head = 0, tail = 0;
            for (int j = n - 1; j >= 0; --j) {
                int k = j + l;
                if (k <= n && dp[k] != -INF) {
                    long long val = dp[k] + presum[k];
                    while (head < tail &&
                           dp[dq[tail - 1]] + presum[dq[tail - 1]] <= val)
                        tail--;
                    dq[tail++] = k;
                }
                while (head < tail && dq[head] > j + r) {
                    head++;
                }
                cur[j] = cur[j + 1];
                if (head < tail) {
                    cur[j] = max(cur[j],
                                 dp[dq[head]] + presum[dq[head]] - presum[j]);
                }
            }
            swap(dp, cur);
        }
        return dp[0];
    }
};