#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > far) return false;
            far = max(far, nums[i] + i);
        }
        return true;
    }
};