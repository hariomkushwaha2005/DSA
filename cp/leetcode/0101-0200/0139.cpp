#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool kaguya(int ind, int a, int b, string& s, vector<int>& v,
                unordered_set<string>& dict) {
        int n = s.size();
        if (ind == n) {
            return v[n];
        }
        for (int i = ind - b + 1; i >= max(0, ind - a + 1); i--) {
            if (v[i] && dict.find(s.substr(i, ind - i + 1)) != dict.end()) {
                v[ind + 1] = 1;
                // break;
            }
        }
        return kaguya(ind + 1, a, b, s, v, dict);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int a = wordDict[0].size();
        int b = a;
        vector<int> v(s.size() + 1, 0);
        v[0] = 1;
        for (int i = 0; i < wordDict.size(); i++) {
            int x = wordDict[i].size();
            a = max(a, x);
            b = min(b, x);
        }
        return kaguya(0, a, b, s, v, dict);
    }
};