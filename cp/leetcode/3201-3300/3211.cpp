#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void mikasa(string& s, bool tight, int n, int i, vector<string>& ans) {
        if (i == n) {
            ans.push_back(s);
            return;
        }
        s[i] = '1';
        mikasa(s, 0, n, i + 1, ans);
        if (!tight) {
            s[i] = '0';
            mikasa(s, 1, n, i + 1, ans);
        }
    }

public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        ans.reserve(7000);
        string s(n, '0');
        mikasa(s, 0, n, 0, ans);
        return ans;
    }
};

