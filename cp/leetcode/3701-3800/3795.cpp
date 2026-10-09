#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size(), r = 0, l = 0;
        int sum = 0;
        vector<int> mp(100001, 0);
        int minn = INT_MAX;
        while (r < n) {
            mp[nums[r]]++;
            if (mp[nums[r]] == 1)
                sum += nums[r];
            while (sum >= k) {
                minn = min(minn, r - l + 1);
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                    sum -= nums[l];
                l++;
            }
            r++;
        }
        return minn == INT_MAX ? -1 : minn;
    }
};