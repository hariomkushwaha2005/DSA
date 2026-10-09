#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int maxx = 0, minn = 0;
        for (int i : nums) {
            maxx += i;
            minn = max(i, minn);
        }
        int ans = 0;
        while (minn <= maxx) {
            int mid = minn + (maxx - minn) / 2;
            int temp = 1, sum = 0;
            for (int i : nums) {
                sum += i;
                if (sum > mid) {
                    temp++;
                    sum = i;
                }
            }
            if (temp <= k)
                maxx = mid - 1;
            else
                minn = mid + 1;
        }
        return minn;
    }
};