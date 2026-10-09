#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, last = 0, slast = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= last) {
                if (nums[i] > slast) {
                    last = nums[i];
                }
                cnt++;
                if (cnt > 1)
                    return false;
            } else {
                slast = last;
                last = nums[i];
            }
        }
        return true;
    }
};