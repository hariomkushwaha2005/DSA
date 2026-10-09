#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, maxx = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                cnt++;
                maxx = max(cnt, maxx);
            } else {
                cnt = 0;
            }
        }
        return maxx;
    }
};