#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int last = 0, slast = 0;
        for(int i = 0; i < n; ++i){
            int cur = max(slast + nums[i], last);
            slast = last;
            last = cur;
        }
        return last;
    }
};