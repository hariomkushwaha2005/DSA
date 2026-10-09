#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int help(int i, int j, int k, int state, string& s, string& t, string& u) {
        if (i == s.size()) {
            return (state == 0) && (k != 0) && (j != 0);
        }

        if (dp[i][j][k][state] != -1)
            return dp[i][j][k][state];

        int ans = 0;
        if (state == 0) {
            ans = (help(i, j, k, 1, s, t, u) + help(i, j, k, 2, s, t, u)) % mod;
        }
        else if (state == 1 && j < t.size()) {
            ans = help(i, j + 1, k, 1, s, t, u);
            if (s[i] == t[j])
                ans = (ans + help(i + 1, j + 1, k, 0, s, t, u)) % mod;
        }
        else if (state == 2 && k < u.size()) {
            ans = help(i, j, k + 1, 2, s, t, u);
            if (s[i] == u[k])
                ans = (ans + help(i + 1, j, k + 1, 0, s, t, u)) % mod;
        }

        return dp[i][j][k][state] = ans;
    }

public:
    int dp[101][101][101][3];
    int mod = 1e9 + 7;
    int interleaveCharacters(string t, string u, string s) {
        memset(dp, -1, sizeof(dp));
        return help(0, 0, 0, 0, s, t, u) % mod;
    }
};