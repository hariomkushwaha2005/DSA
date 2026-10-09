#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            map<char, int> mp;
            int maxx = INT_MIN;
            for (int j = i; j < n; j++) {
                mp[s[j]]++;
                maxx = max(maxx, mp[s[j]]);
                int minn = INT_MAX;
                for (auto it : mp) {
                    minn = min(minn, it.second);
                }
                ans += maxx - minn;
            }
        }
        return ans;
    }
};