#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        string t = "1#";
        for (auto& c : s) {
            t += c;
            t += '#';
        }
        t += "2";

        int n = t.size();
        int c = 0, r = 0;
        vector<int> p(n, 0);
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            int m = 2 * c - i;

            if (m >= 0 && i + p[m] < r) {
                p[i] = p[m];
            } else {
                p[i] = r - i < 0 ? 0 : r - i;
                while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) {
                    p[i]++;
                }
                r = i + p[i];
                c = i;
            }
            ans += (p[i] + 1) / 2;
        }
        return ans;
    }
};