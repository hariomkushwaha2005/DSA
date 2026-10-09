#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minLights(vector<int> &lights)
    {
        int n = lights.size();
        string bulb(n, 0);
        const int *l = lights.data();
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            cur = max(cur, l[i]);
            bulb[i] = cur > 0;
            cur -= cur > l[i];
        }
        cur = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            cur = max(cur, l[i]);
            bulb[i] |= cur > 0;
            cur -= cur > l[i];
        }
        int ans = 0, zero = 0;
        for (int i = 0; i < n; i++)
        {
            if (bulb[i])
            {
                if (zero)
                {
                    ans += (zero + 2) / 3;
                    zero = 0;
                }
            }
            else
            {
                zero++;
            }
        }
        ans += (zero + 2) / 3;
        return ans;
    }
};