#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void mikasa(vector<string>& ans, string& s, int i, int k, bool last) {
        if (k < 0)
            return;
        if (i == s.size()) {
            ans.push_back(s);
            return;
        }
        mikasa(ans, s, i + 1, k, 0);
        if (!last) {
            s[i] = '1';
            mikasa(ans, s, i + 1, k - i, 1);
            s[i] = '0';
        }
    }

public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> ans;
        string s(n, '0');
        mikasa(ans, s, 0, k, 0);
        return ans;
    }
};