#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int len = 0;
        int l = -1, last = !(nums[0] & 1);
        for (int i = 0; i < n; i++) {
            if (nums[i] > threshold) {
                l = -1;
                continue;
            }
            if ((nums[i] & 1) == last) {
                l = -1;
            }
            if (!(nums[i] & 1) && l == -1)
                l = i;
            if (l != -1)
                len = max(len, i - l + 1);
            last = nums[i] & 1;
        }
        return len;
    }
};