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

    vll a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    map<ll, ll> mp;
    vll c(n, 1e5);
    ll ans = 0;
    for (int i = 0; i < n - 4; ++i)
    {
        ll x = a[i] + a[i + 2] - a[i + 4];
        mp[x]++;
        ans += (mp[x] - 1);
        c[i] = x;
    }

    for (int i = 0; i < n - 4; ++i)
    {
        if (c[i] == c[i + 2])
            ans--;
        if (c[i] == c[i + 4])
            ans--;
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