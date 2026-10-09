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

    vll v(n + 1, n + 1);
    for (int i = 0; i < m; ++i)
    {
        ll x, y;
        cin >> x >> y;

        if (x > y)
            swap(x, y);

        v[x] = min(v[x], y);
    }

    ll ans = 0, cnt = 0;
    for (int i = n; i > 0; --i)
    {
        cnt++;
        ll next = v[i] - i;
        cnt = min(cnt, next);
        ans += cnt;
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