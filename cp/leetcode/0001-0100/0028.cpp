#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m == 0)
            return 0;
        if (m > n)
            return -1;

        vector<int> lps(m, 0);
        int i = 1, l = 0;
        while (i < m) {
            if (needle[i] == needle[l]) {
                l++;
                lps[i] = l;
                i++;
            } else if (l == 0) {
                lps[i] = 0;
                i++;
            } else {
                l = lps[l - 1];
            }
        }
        i = 0, l = 0;
        while (i < n) {
            if (needle[l] == haystack[i]) {
                i++;
                l++;
                if (l == m)
                    return i - m;
            } else if (l != 0) {
                l = lps[l - 1];
            } else {
                i++;
            }
        }
        return -1;
    }
};