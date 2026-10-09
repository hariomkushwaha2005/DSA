#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool less(vector<int>& a, vector<int>& b) {
        return (a[0] >= b[0]) && (a[1] >= b[1]) && (a[2] >= b[2]);
    }

    int help(int i, int last, vector<vector<int>>& cuboids,
             vector<vector<int>>& dp) {
        int n = cuboids.size();
        if (i >= n)
            return 0;
        if (dp[i][last + 1] != -1)
            return dp[i][last + 1];

        int ans = help(i + 1, last, cuboids, dp);
        if (last == -1 || less(cuboids[last], cuboids[i]))
            ans = max(ans, cuboids[i][2] + help(i + 1, i, cuboids, dp));

        return dp[i][last + 1] = ans;
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for (int i = 0; i < n; ++i)
            sort(cuboids[i].begin(), cuboids[i].end());

        sort(cuboids.rbegin(), cuboids.rend());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return help(0, -1, cuboids, dp);
    }
};