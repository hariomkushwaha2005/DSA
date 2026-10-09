#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int exp = 0;
        for (int i = 0; i < n; i++) {
            ans += max(0, exp - nums[i]);
            exp = max(exp + 1, nums[i] + 1);
        }
        return ans;
    }
};