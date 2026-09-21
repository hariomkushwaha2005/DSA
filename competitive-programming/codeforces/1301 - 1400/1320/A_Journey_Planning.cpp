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

    ll off = 400000;
    vector<ll> v((off << 1), 0);
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ll x;
        cin >> x;
        v[x - i + off] += x;
        ans = max(v[x - i + off], ans);
    }
    cout << ans << endl;
}

int main()
{
    fast_io();

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}