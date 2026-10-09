#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, r = 0, n = s.size(), ans = 0;
        vector<int> v(3);
        while (r < n) {
            v[s[r] - 'a']++;
            while (v[0] > 0 && v[1] > 0 && v[2] > 0) {
                ans += n - r;
                v[s[l] - 'a']--;
                l++;
            }
            r++;
        }
        return ans;
    }
};