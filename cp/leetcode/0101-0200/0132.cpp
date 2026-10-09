#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool eren(int i, int j, string &s)
    {
        while (i < j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
    }
    // int mikasa(int i, string& s, vector<int>& dp) {
    //     int n = s.size();
    //     if (i == n || eren(i, n - 1, s))
    //         return 0;
    //     if (dp[i] != -1)
    //         return dp[i];
    //     int val = INT_MAX;
    //     for (int k = n-1; k >=i; k--) {
    //         if (eren(i, k, s)) {
    //             val = min(val, 1 + mikasa(k + 1, s, dp));
    //         }
    //     }
    //     return dp[i] = val;
    // }

public:
    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            int val = INT_MAX;
            for (int j = n - 1; j >= i; j--)
            {
                if (eren(i, j, s))
                    val = min(val, 1 + dp[j + 1]);
            }
            dp[i] = val;
        }
        return dp[0];
    }
};