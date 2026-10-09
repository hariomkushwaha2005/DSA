#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxi = 0, ans = 0;
        vector<int> mpp(26);
        while (r < s.size()) {
            mpp[s[r]-'A']++;
            maxi = max(maxi, mpp[s[r]-'A']);
            if (r - l + 1 - maxi > k) {
                mpp[s[l]-'A']--;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};