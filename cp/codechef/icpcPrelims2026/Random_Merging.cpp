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

ll inv(ll a)
{
    ll b = mod - 2;
    ll val = 1;
    a %= mod;
    while (b > 1)
    {
        if (b & 1)
            val = val * a % mod;

        a = a * a % mod;
        b >>= 1;
    }
    return val * a % mod;
}

void solve()
{
    ll n;
    cin >> n;

    vll v(n);
    for (auto &i : v)
        cin >> i;

    vll h(n + 1);
    h[0] = 0;
    for (int i = 1; i <= n; ++i)
        h[i] = (h[i - 1] + inv(i)) % mod;

    ll ans = 0;
    for (int i = 0; i < n; ++i)
        ans = (ans + v[i] * (h[i] + h[n - i - 1]) % mod) % mod;

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