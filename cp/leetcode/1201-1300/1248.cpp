#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        int n = nums.size();
        int r = 0, l = 0, odd = 0, ans = 0;
        while (r < n) {
            if (nums[r] & 1)
                odd++;
            while (odd > k) {
                odd -= (nums[l] & 1);
                l++;
            }
            ans += r - l + 1;
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};