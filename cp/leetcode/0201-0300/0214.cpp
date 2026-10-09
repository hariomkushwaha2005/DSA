#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();

        vector<int> lcs(n, 0);
        int i = 1, l = 0;

        while (i < n) {
            if (s[i] == s[l]) {
                l++;
                lcs[i] = l;
                i++;
            } else if (l != 0) {
                l = lcs[l - 1];
            } else {
                i++;
            }
        }

        i = n - 1, l = 0;
        int maxi = 0;
        while (i >= 0) {
            if (s[i] == s[l]) {
                l++;
                i--;
            } else if (l != 0) {
                l = lcs[l - 1];
            } else {
                i--;
            }
        }
        string a = s.substr(l);
        reverse(a.begin(), a.end());
        return a + s;
    }
};