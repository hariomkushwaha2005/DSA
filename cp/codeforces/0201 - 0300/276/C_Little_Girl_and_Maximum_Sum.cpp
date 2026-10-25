#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

void solve()
{
    ll n, q;
    cin >> n >> q;

    vll v(n);
    for (auto &i : v)
        cin >> i;

    vll a(n, 0);
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        a[x - 1] += 1;
        if (y < n)
            a[y] -= 1;
    }

    for (int i = 1; i < n; ++i)
        a[i] += a[i - 1];

    ranges::sort(a);
    ranges::sort(v);
    ll ans = 0;
    for (int i = 0; i < n; ++i)
        ans += a[i] * v[i];

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}