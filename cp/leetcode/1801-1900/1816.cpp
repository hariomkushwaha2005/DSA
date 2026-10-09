#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string truncateSentence(const string& s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            k -= s[i] == ' ';
            if (k == 0)
                return s.substr(0, i);
        }
        return s;
    }
};
