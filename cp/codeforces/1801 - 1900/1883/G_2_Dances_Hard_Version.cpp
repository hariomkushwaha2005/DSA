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

    vll a(n - 1);

    for (int i = 0; i < n - 1; ++i)
        cin >> a[i];

    vll b(n);
    for (auto &x : b)
        cin >> x;

    sort(all(a));
    sort(all(b));

    ll i = 0, j = 0;
    ll skipped = 0;
    for (; i < n - 1; ++i, ++j)
    {
        while (j < n && a[i] >= b[j])
        {
            skipped = b[j];
            ++j;
        }
        if (j == n)
            break;
    }

    if (j < n)
        skipped = b[n - 1];

    ll x = min(m, skipped - 1);
    ll ans = x * (n - i - 1);
    ans += (m - x) * (n - i);
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