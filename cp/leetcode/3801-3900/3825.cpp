#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int LIS(vector<int>& arr) {
        vector<int> lis;
        for (int x : arr) {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            if (it == lis.end())
                lis.push_back(x);
            else
                *it = x;
        }
        return lis.size();
    }

    int longestSubsequence(vector<int>& nums) {
        int ans = 0;

        for (int b = 0; b < 31; b++) {
            vector<int> filtered;
            for (int x : nums) {
                if (x & (1 << b))
                    filtered.push_back(x);
            }
            if (!filtered.empty())
                ans = max(ans, LIS(filtered));
        }

        return ans;
    }
};