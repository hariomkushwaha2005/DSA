#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(const string& s) {
        int n = s.size();
        int b = 0, l = 1;
        string ans;
        ans.reserve(n);
        for (char c : s) {
            if (c == '(') {
                if (b > 0)
                    ans += c;
                b++;
            } else {
                b--;
                if (b > 0)
                    ans += c;
            }
        }
        return ans;
    }
};