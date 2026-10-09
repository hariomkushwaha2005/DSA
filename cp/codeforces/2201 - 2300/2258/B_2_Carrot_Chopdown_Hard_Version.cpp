#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

#define endl '\n'

inline void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    ll sum = 0;
    vll a(m + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        ll b;
        cin >> b;
        sum += b;
        a[b]++;
    }

    vll b(m + 2, 0);
    for (int i = m; i >= 1; --i)
        b[i] = b[i + 1] + a[i];

    ll c = __lg(m);
    vll d(c + 1, 0);
    for (int i = 1; i <= ((m + 1) >> 1); ++i)
    {
        ll e = 0, f = 1;
        for (int j = 1; j <= c; ++j)
        {
            ll h = (1LL << j);
            while (f < h && f * i <= m)
            {
                e += b[f * i];
                ++f;
            }
            ll g = e;
            if ((1LL << j) * i <= m)
                g += a[(1LL << j) * i];
            d[j] = max(d[j], g);
        }
    }
    for (int i = 1; i <= c; ++i)
    {
        d[i] = max(d[i], d[i - 1]);
        cout << d[i] << " ";
    }
    for (int i = c + 1; i <= m; ++i)
        cout << sum << " ";
    cout << endl;
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