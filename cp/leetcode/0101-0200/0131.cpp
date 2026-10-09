#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool palin(string& s, int i, int j) {
        while (i <= j && s[i] == s[j]) {
            ++i;
            --j;
        }
        return i > j;
    }
    void help(int st, int end, string& s, vector<string>& cur,
              vector<vector<string>>& ans) {
        if (st >= s.size())
            ans.push_back(cur);
        if (end >= s.size())
            return;

        if (palin(s, st, end)) {
            cur.push_back(s.substr(st, end - st + 1));
            help(end + 1, end + 1, s, cur, ans);
            cur.pop_back();
        }
        help(st, end + 1, s, cur, ans);
    }
    vector<vector<string>> partition(string& s) {
        vector<vector<string>> ans;
        vector<string> cur;
        help(0, 0, s, cur, ans);
        return ans;
    }
};