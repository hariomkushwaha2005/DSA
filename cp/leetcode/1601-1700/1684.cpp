#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countConsistentStrings(const string& allowed,
                               const vector<string>& words) {
        int mask = 0;
        for (char c : allowed) {
            mask |= (1 << (c - 'a'));
        }
        int ans = 0;
        for (const string& it : words) {
            bool match = 1;
            for (char c : it) {
                if ((mask & (1 << (c - 'a'))) == 0) {
                    match = 0;
                    break;
                }
            }
            ans += match;
        }
        return ans;
    }
};