#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();

        vector<int> lps(n, 0);
        int l = 0, i = 1;
        while (i < n) {
            if (s[l] == s[i]) {
                l++;
                lps[i] = l;
                i++;
            } else if (l != 0) {
                l = lps[l - 1];
            } else {
                i++;
            }
        }
        return s.substr(0, lps[n - 1]);
    }
};