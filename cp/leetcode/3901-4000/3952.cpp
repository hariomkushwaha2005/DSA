#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = s.length();
        ll ans = 0;
        int last = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                last = i;
            else {
                if (last != -1 && nums[i] < nums[last]) {
                    ans += 1LL * nums[last];
                    last = i;
                } else {
                    ans += 1LL*nums[i];
                }
            }
        }
        return ans;
    }
};