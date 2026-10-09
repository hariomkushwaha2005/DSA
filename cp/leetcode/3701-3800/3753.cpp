#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
private:
    pair<ll, ll> digitDP(string& s, int idx, int prev2, int prev1, bool tight,
                         bool lz, pair<ll, ll> DP[][11][11][2][2]) {

        if (idx == s.size())
            return {1, 0};

        int cur = s[idx] - '0';

        if (DP[idx][prev2 + 1][prev1 + 1][tight][lz].first != -1)
            return DP[idx][prev2 + 1][prev1 + 1][tight][lz];

        int limit = tight ? cur : 9;
        ll num = 0, wavy = 0;
        for (int i = 0; i <= limit; i++) {
            bool nextLz = (lz && i == 0);
            int nextPrev1 = nextLz ? -1 : i;
            int nextPrev2 = lz ? -1 : prev1;
            bool nextTight = (tight && i == cur);

            auto x = digitDP(s, idx + 1, nextPrev2, nextPrev1, nextTight,
                             nextLz, DP);
            wavy += x.second;
            num += x.first;
            if (prev2 != -1 &&
                ((prev2 < prev1 && prev1 > i) || (prev2 > prev1 && prev1 < i)))
                wavy += x.first;
        }
        return DP[idx][prev2 + 1][prev1 + 1][tight][lz] = {num, wavy};
    }

public:
    ll totalWaviness(ll num1, ll num2) {
        pair<ll, ll> DP[16][11][11][2][2];
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 11; j++) {
                for (int k = 0; k < 11; k++) {
                    for (int l = 0; l < 2; l++) {
                        for (int m = 0; m < 2; m++) {
                            DP[i][j][k][l][m] = {-1, -1};
                        }
                    }
                }
            }
        }
        string s2 = to_string(num2);
        auto x = digitDP(s2, 0, -1, -1, 1, 1, DP);
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 11; j++) {
                for (int k = 0; k < 11; k++) {
                    for (int l = 0; l < 2; l++) {
                        for (int m = 0; m < 2; m++) {
                            DP[i][j][k][l][m] = {-1, -1};
                        }
                    }
                }
            }
        }
        string s1 = to_string(num1 - 1);
        auto y = digitDP(s1, 0, -1, -1, 1, 1, DP);
        return x.second - y.second;
    }
};