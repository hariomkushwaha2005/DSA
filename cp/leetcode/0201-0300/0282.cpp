#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void kaguya(int i, long last, long val, int k, string s, string& num,
                vector<string>& ans) {
        if (i == num.size()) {
            if (val == k)
                ans.push_back(s);
            return;
        }
        for (int j = i; j < num.size(); j++) {
            string cu = num.substr(i, j - i + 1);
            long cur = stoll(cu);
            if (j > i && num[i] == '0')
                return;
            if (i == 0)
                kaguya(j + 1, cur, cur, k, s + cu, num, ans);
            else {
                kaguya(j + 1, last * cur, val - last + last * cur, k,
                       s + '*' + cu, num, ans);
                kaguya(j + 1, cur, val + cur, k, s + '+' + cu, num, ans);
                kaguya(j + 1, -cur, val - cur, k, s + '-' + cu, num, ans);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string s = "";
        kaguya(0, 0, 0, target, s, num, ans);
        return ans;
    }
};