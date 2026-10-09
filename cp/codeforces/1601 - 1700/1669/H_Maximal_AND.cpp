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
    ll n, k;
    cin >> n >> k;

    vll v(31, 0);
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;

        ll a = 1;
        while (x >= a)
        {
            if (x & a)
            {
                int c = 31 - __builtin_clz(a);
                v[c]++;
            }
            a <<= 1;
        }
    }

    ll ans = 0;

    for (int i = 30; i >= 0; --i)
    {
        if (v[i] + k >= n)
        {
            k -= n - v[i];
            ans += (1 << i);
        }
    }

    cout << ans << endl;
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