#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeCharacters(string s, int k) {
        unordered_map<char, int> mp;
        int l = 0, r = 0;
        while (r < s.size()) {
            if (mp.count(s[r])) {
                s.erase(r, 1);
            } else {
                mp[s[r]]++;
                if (mp.size() > k) {
                    mp[s[l]]--;
                    if (mp[s[l]] == 0)
                        mp.erase(s[l]);
                    l++;
                }
                r++;
            }
        }
        return s;
    }
};