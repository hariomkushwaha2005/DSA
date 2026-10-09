#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int xorr = 0;
        for (int num : nums)
            xorr ^= num;
        return xorr;
    }
};