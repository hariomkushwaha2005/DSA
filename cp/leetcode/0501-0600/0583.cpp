#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int longestCommonSubsequence(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int> curr(m + 1, 0), prev(m + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            swap(prev, curr);
        }
        return prev[m];
    }

public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        int x = longestCommonSubsequence(word1, word2);
        return n + m - 2 * x;
    }
};