#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mp;
        int zero = 0, one = 0;
        mp[0]=-1;
        for (int i = 0; i < n; i++) {
            if (nums[i] & 1)
                one++;
            else
                zero++;
            if (!mp.count(zero - one))
                mp[zero - one] = i;
            else {
                ans = max(ans, i - mp[zero - one]);
            }
        }
        return ans;
    }
};