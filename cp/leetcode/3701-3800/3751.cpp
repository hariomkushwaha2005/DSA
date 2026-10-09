#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    pair<int, int> dp[6][11][11][2];
    pair<int, int> mikasa(const string& s, int ind, int prev, int prev2,
                          bool tight, bool zero) {
        if (ind == s.size())
            return {1, 0};

        int rem = s.size() - ind;
        if (!tight && dp[rem][prev2 + 1][prev + 1][zero].first != -1)
            return dp[rem][prev2 + 1][prev + 1][zero];

        int dig = s[ind] - '0';
        int maxx = tight ? dig : 9;
        int num = 0, val = 0;

        for (int i = 0; i <= maxx; i++) {
            bool nextzero = zero && (i == 0);
            bool nexttight = tight && (i == maxx);

            pair<int, int> ans = mikasa(s, ind + 1, nextzero ? -1 : i, prev,
                                        nexttight, nextzero);

            num += ans.first;
            val += ans.second;

            if ((prev2 != -1) && (!zero) &&
                ((prev < prev2 && prev < i) || (prev > prev2 && prev > i)))
                val += ans.first;
        }

        if (!tight)
            dp[rem][prev2 + 1][prev + 1][zero] = {num, val};
        return {num, val};
    }
    int getwavy(int num) {
        string s = to_string(num);
        return mikasa(s, 0, -1, -1, 1, 1).second;
    }

public:
    Solution() { memset(dp, -1, sizeof(dp)); }
    int totalWaviness(int num1, int num2) {
        return getwavy(num2) - getwavy(num1 - 1);
    }
};