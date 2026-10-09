#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];
        long long pro = 1;
        int ans = -1;
        for (int i = n - 1; i >= 0; i--) {
            sum -= nums[i];
            if (pro == sum)
                ans = i;
            if (pro >= sum||pro > LLONG_MAX / nums[i]) {
                break;
            } else {
                pro *= nums[i];
            }
        }
        return ans;
    }
};