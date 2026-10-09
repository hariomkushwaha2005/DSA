#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n);
        pre[n - 1] = nums[n - 1];
        int ans = 0;
        for (int i = n - 2; i >= k; --i) {
            pre[i] = max(nums[i], pre[i + 1]);
        }
        for (int i = 0; i < n - k; ++i) {
            ans = max(ans, nums[i] + pre[i + k]);
        }
        return ans;
    }
};