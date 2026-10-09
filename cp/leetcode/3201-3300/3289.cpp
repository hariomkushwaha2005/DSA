#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;
        for (auto& x : nums)
            xorr ^= x;
        for (int i = 0; i < n - 2; i++)
            xorr ^= i;
        int bit = (xorr & (-xorr));
        int a = 0, b = 0;
        for (auto& x : nums) {
            if (x & bit)
                a ^= x;
            else
                b ^= x;
        }
        for (int i = 1; i < n - 2; i++) {
            if (i & bit)
                a ^= i;
            else
                b ^= i;
        }
        return {a, b};
    }
};