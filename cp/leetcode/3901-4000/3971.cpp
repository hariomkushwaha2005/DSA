#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    long long mikasa(int val, const vector<int> &values,
                     const vector<int> &decay)
    {
        int n = values.size();
        long long res = 0;

        const int *v = values.data();
        const int *d = decay.data();

        for (int i = 0; i < n; i++)
        {
            if (v[i] <= val)
                continue;

            res += (v[i] - val + d[i] - 1) / d[i];
        }
        return res;
    }

public:
    const int mod = 1e9 + 7;

    int maxTotalValue(const vector<int> &value, const vector<int> &decay,
                      int mu)
    {
        int n = value.size();
        int low = 0;
        int high = *max_element(value.begin(), value.end());
        __int128_t m = mu;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (mikasa(mid, value, decay) >= m)
                low = mid + 1;
            else
                high = mid - 1;
        }

        __int128_t ans = 0;

        const int *v = value.data();
        const int *d = decay.data();

        for (int i = 0; i < n; i++)
        {
            if (v[i] <= high)
                continue;

            __int128_t x = (v[i] - high + d[i] - 1) / d[i];
            __int128_t pairs = (x * (x - 1)) >> 1;
            ans += v[i] * x - pairs * d[i];
            m -= x;
        }

        if (m < 0)
            ans += m * (high + 1);

        return ans % mod;
    }
};