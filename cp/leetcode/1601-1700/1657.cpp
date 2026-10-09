#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length();
        if (n != word2.length())
            return false;
        vector<int> f1(26, 0), f2(26, 0);
        for (int i = 0; i < n; ++i) {
            f1[word1[i] - 'a']++;
            f2[word2[i] - 'a']++;
        }
        vector<int> v(n + 1, 0);
        for (int i = 0; i < 26; ++i) {
            v[f1[i]]++;
            if ((f1[i] == 0 || f2[i] == 0) && (f1[i] | f2[i]))
                return false;
        }
        for (int i = 0; i < 26; ++i) {
            v[f2[i]]--;
            if (v[f2[i]] < 0)
                return false;
        }
        return true;
    }
};