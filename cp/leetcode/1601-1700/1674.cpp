#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);
        for (int i = 0; i < n / 2; ++i) {
            int minn = min(nums[i], nums[n - 1 - i]);
            int maxx = max(nums[i], nums[n - 1 - i]);
            diff[2] += 2;
            diff[minn + 1] -= 1;
            diff[minn + maxx] -= 1;
            diff[minn + maxx + 1] += 1;
            diff[maxx + limit + 1] += 1;
        }
        int ans = n;
        int cur = 0;
        for (int i = 2; i < 2 * limit + 2; ++i) {
            cur += diff[i];
            ans = min(ans, cur);
        }
        return ans;
    }
};