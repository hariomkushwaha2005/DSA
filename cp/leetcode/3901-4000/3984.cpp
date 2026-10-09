#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;
    int divisibleGame(vector<int>& nums) {
        int n = nums.size();
        int maxx = nums[0];
        for (int i = 1; i < n; ++i) {
            maxx = max(maxx, nums[i]);
        }
        if (maxx == 1)
            return 1000000005;
        vector<int> sieve(maxx + 1, 0);
        for (int i = 0; i < n; ++i) {
            int cur = nums[i];
            int j = 2;
            while (j * j <= cur) {
                while (cur % j == 0) {
                    sieve[j] = 1;
                    cur /= j;
                }
                ++j;
            }
            if (cur > 1)
                sieve[cur] = 1;
        }
        long long ans = -1;
        int k = 2;
        for (int i = 2; i <= maxx; ++i) {
            if (sieve[i]) {
                int cur = find(i, nums);
                if (cur > ans) {
                    ans = cur;
                    k = i;
                }
            }
        }
        return (k * ans + mod) % mod;
    }
    int find(int k, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] % k)
                sum -= nums[i];
            else
                sum += nums[i];
            ans = max(ans, sum);
            sum = max(sum, 0);
        }
        return ans;
    }
};