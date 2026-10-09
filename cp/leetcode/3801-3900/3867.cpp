#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        int maxx = nums[0];
        for (int i = 0; i < n; i++) {
            maxx = max(maxx, nums[i]);
            v[i] = __gcd(maxx, nums[i]);
        }
        sort(v.begin(), v.end());
        int l = 0, r = n - 1;
        long long ans = 0;
        while (l < r) {
            ans += __gcd(v[r], v[l]);
            r--;
            l++;
        }
        return ans;
    }
};