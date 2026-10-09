#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

inline void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    ll n;
    cin >> n;

    vll v(3 * n);
    for (auto &it : v)
        cin >> it;

    ranges::sort(v, greater<>());

    vll pre(3 * n + 1, 0);
    for (int i = 0; i < 3 * n; ++i)
        pre[i + 1] = pre[i] + v[i];

    ll ba = 0, bb = 0, bc = 3 * n;
    ll bs = 2 * pre[ba] + pre[ba + 2 * bb] + 3 * pre[bc];
    for (ll a = 0; a <= n; ++a)
    {
        ll l = 0, h = n - a - 1;
        ll bop = 0;
        while (l <= h)
        {
            ll b = ((l + h) >> 1);
            ll val = v[a + 2 * b] + v[a + 2 * b + 1] - 3 * v[3 * n - 2 * a - b - 1];
            if (val >= 0)
            {
                bop = b + 1;
                l = b + 1;
            }
            else
                h = b - 1;
        }
        ll c = 3 * n - 2 * a - bop;
        ll fs = 2 * pre[a] + pre[a + 2 * bop] + 3 * pre[c];
        if (fs > bs)
        {
            ba = a;
            bb = bop;
            bc = c;
            bs = fs;
        }
    }
    cout << bs << endl;
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