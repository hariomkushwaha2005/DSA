#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        n = 1 << n;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int xorr = 0;
            for (int j = 0; j < nums.size(); j++) {
                if ((1 << j) & i)
                    xorr ^= nums[j];
            }
            ans += xorr;
        }
        return ans;
    }
};