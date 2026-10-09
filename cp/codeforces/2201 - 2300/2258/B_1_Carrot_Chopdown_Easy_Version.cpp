#include <bits/stdc++.h>
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
    ll n, m;
    cin >> n >> m;

    vll v(m + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        v[x]++;
    }

    ll cnt = 0;
    ll ans = n;
    for (int i = 1; i <= m; ++i)
    {
        ll p = n - cnt;
        if (i <= (m >> 1))
            p += v[(i << 1)];
        ans = max(ans, p);
        cnt += v[i];
    }
    cout << ans << "\n";
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