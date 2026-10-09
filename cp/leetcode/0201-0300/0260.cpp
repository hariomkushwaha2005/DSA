#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;
        for (int i = 0; i < n; i++) {
            xorr ^= nums[i];
        }
        int k = 1;
        while (!(xorr & k))
            k <<= 1;
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] & k)
                a ^= nums[i];
            else
                b ^= nums[i];
        }
        if (a >= b)
            return {b, a};
        return {a, b};
    }
};