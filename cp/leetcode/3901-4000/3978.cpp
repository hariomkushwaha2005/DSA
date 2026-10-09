#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int num = nums[n/2];
        for(int i = 0; i < n/2; ++i){
            if(nums[i] == num || nums[n - 1 - i] == num) return false;
        }
        return true;
    }
};