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

ll mod = 998244353;
ll power(ll base, ll exp)
{
    ll res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

ll modinv(ll n)
{
    return power(n, mod - 2);
}

void solve()
{
    ll n;
    cin >> n;

    vll v(n);
    for (auto &x : v)
        cin >> x;

    ranges::sort(v);
    ranges::reverse(v);

    ll val = 1;
    for (int i = 1; i < n; ++i)
    {
        val = (val * i) % mod;
    }

    ll ans = 0;
    ll x = v[0];
    for (int i = 1; i < n; ++i)
    {
        ans = (ans + x * val % mod * modinv(i) % mod) % mod;
        ans = (ans - v[i] * val % mod + mod) % mod;
        x = (x + v[i]) % mod;
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