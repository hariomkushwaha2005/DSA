#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(__builtin_popcount(i) == k) sum += nums[i];
        }
        return sum;
    }
};