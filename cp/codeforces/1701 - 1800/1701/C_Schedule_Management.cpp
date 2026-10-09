#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

inline void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    vll v(n, 0);
    for (int i = 0; i < m; ++i)
    {
        ll x;
        cin >> x;
        v[x - 1]++;
    }

    sort(v.rbegin(), v.rend());
    ll l = v[n - 1], h = v[0];

    while (l <= h)
    {
        ll mid = l + ((h - l) >> 1);
        int i = 0;
        ll x = 0;

        while (i < n && v[i] > mid)
        {
            x += v[i] - mid;
            ++i;
        }
        while (i < n)
        {
            ll y = ((mid - v[i]) >> 1);
            x -= y;
            ++i;
        }

        if (x > 0)
            l = mid + 1;
        else
            h = mid - 1;
    }

    cout << l << endl;
}

int main()
{
    fast_io();

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}