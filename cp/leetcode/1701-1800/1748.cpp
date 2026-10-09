#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> vis(101, 0);
        int ans = 0;
        for (auto& it : nums) {
            vis[it]++;
            if (vis[it] == 1) {
                ans += it;
            } else if (vis[it] == 2)
                ans -= it;
        }
        return ans;
    }
};