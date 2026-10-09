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

ll mod = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;

    ll b = -1;

    vll a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        b &= a[i];
    }

    ranges::sort(a);

    ll cnt = count(a.begin(), a.end(), b);

    ll ans = cnt * (cnt - 1) % mod;
    for (int i = n - 2; i > 1; --i)
        ans = (ans * i) % mod;

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