#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int i = 0, j = 0;
        for (char c : t) {
            j = max(j + (s[j] == c), i + 1);
            i += (s[i] == c);
        }
        return j >= n;
    }
};