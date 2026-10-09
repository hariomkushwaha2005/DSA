#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution
{
public:
    long long minCuttingCost(int n, int m, int k)
    {
        ll cost = 0;
        while (n > k)
        {
            cost += 1LL * k * (n - k);
            n -= k;
        }
        while (m > k)
        {
            cost += 1LL * k * (m - k);
            m -= k;
        }
        return cost;
    }
};