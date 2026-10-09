#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int j;
        for (int i = 1; i < (n << 1); i += 2) {
            nums[i] += (nums[n + (i >> 1)]%1001) * 1001;
            j = (n << 1) - i - 1;
            nums[j] += (nums[(j >> 1)]%1001)*1001;
        }
        for(auto &num : nums){
            num /= 1001;
        }
        return nums;
    }
};