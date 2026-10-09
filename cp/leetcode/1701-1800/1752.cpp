#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int last = 0;
        for (auto& it : nums) {
            if (it < last)
                cnt++;
            if (cnt > 1)
                return false;
            last = it;
        }
        if (cnt == 0 || (cnt == 1 && nums[0] >= nums[n - 1]))
            return true;
        return false;
    }
};