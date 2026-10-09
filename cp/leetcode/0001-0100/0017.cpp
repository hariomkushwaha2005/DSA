#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> arr = {"",    "",    "abc",  "def", "ghi",
                          "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void help(int i, int n, string& digits, string& s, vector<string>& ans) {
        if (i == n) {
            ans.push_back(s);
            return;
        }
        for (auto c : arr[digits[i] - '0']) {
            s[i] = c;
            help(i + 1, n, digits, s, ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> ans;
        string s(n, '0');
        help(0, n, digits, s, ans);
        return ans;
    }
};