#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int k;
    int len;
    int s[16];
    long long dp[352];
    long long goodIntegers(long long l, long long r, int kk)
    {
        k = kk;
        memset(dp, -1, sizeof(dp));
        return eren(r) - eren(l - 1);
    }

private:
    long long eren(long long n)
    {
        if (n < 10)
            return 0;
        len = 0;
        while (n > 0)
        {
            s[len++] = n % 10;
            n /= 10;
        }
        int i = 0;
        while (i < len / 2)
        {
            swap(s[i], s[len - i - 1]);
            i++;
        }
        return mikasa(0, -1, 1, 1);
    }

    long long mikasa(int idx, int prev, bool tight, bool zero)
    {
        if ((idx == len - 1) && zero)
            return 0;
        if (idx == len)
            return 1;
        int ind = len - idx - 1;
        int dpi = ind * 22 + ((prev + 1) << 1) + zero;
        if (!tight && dp[dpi] != -1)
            return dp[dpi];
        int num = s[idx];
        int maxx = tight ? num : 9;
        long long ans = 0;
        for (int i = 0; i <= maxx; i++)
        {
            if (prev == -1 || abs(prev - i) <= k)
            {
                bool nexttight = tight && (i == maxx);
                bool nextzero = zero && (i == 0);
                ans += mikasa(idx + 1, nextzero ? -1 : i, nexttight, nextzero);
            }
        }
        if (!tight)
            dp[dpi] = ans;
        return ans;
    }
};