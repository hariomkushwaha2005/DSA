#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n = word1.size(), m = word2.size();
        int i = 0, j = 0, l = 0, r = 0;
        while (i < n && j < m) {
            while (l < word1[i].size() && r < word2[j].size()) {
                if (word1[i][l] != word2[j][r]) {
                    return false;
                }
                l++;
                r++;
            }
            if (l == word1[i].size()) {
                i++;
                l = 0;
            }
            if (r == word2[j].size()) {
                j++;
                r = 0;
            }
        }
        if (i < n || j < m)
            return false;
        return true;
    }
};