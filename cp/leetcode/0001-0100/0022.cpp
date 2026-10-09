#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void help(int o, int c, string& s, vector<string>& ans) {
        if (o == 0 && c == 0)
            ans.push_back(s);
        if (o > 0) {
            s.push_back('(');
            help(o - 1, c, s, ans);
            s.pop_back();
        }
        if (c > o) {
            s.push_back(')');
            help(o, c - 1, s, ans);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string> ans;
        help(n, n, s, ans);
        return ans;
    }
};