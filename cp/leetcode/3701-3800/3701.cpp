#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += (i&1) ? -nums[i] : nums[i];
        }
        return sum;
    }
};