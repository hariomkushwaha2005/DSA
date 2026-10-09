#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool match(int& l, int& r, string& s, string& p) {
        if (r < 0)
            return true;
        for (; l < s.size(); l++) {
            if (s[l] == p[0]) {
                bool can = 1;
                for (int i = 0; i <= r; i++) {
                    if (s[l + i] != p[i]) {
                        can = 0;
                        break;
                    }
                }
                if (can) {
                    l = l + r + 1;
                    return 1;
                }
            }
        }
        return 0;
    }

public:
    bool hasMatch(string s, string p) {
        int n = s.size();
        int l1 = 0, r1 = 0;
        while (p[r1] != '*')
            r1++;
        r1--;
        if (!match(l1, r1, s, p))
            return 0;
        reverse(s.begin(), s.end());
        reverse(p.begin(), p.end());
        int l2 = 0, r2 = p.size() - r1 - 3;
        if (!match(l2, r2, s, p))
            return 0;
        if (l1 + l2 <= n)
            return 1;
        return 0;
    }
};