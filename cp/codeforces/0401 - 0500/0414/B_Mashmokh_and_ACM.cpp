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

ll lucy(ll a, ll i, ll k, ll n, vector<vll> &dp)
{
    if (i >= k)
        return 1;

    if (dp[a][i] != -1)
        return dp[a][i];

    ll b = a;
    ll ans = 0;
    while (b <= n)
    {
        ans = (ans + lucy(b, i + 1, k, n, dp)) % mod;
        b += a;
    }
    return dp[a][i] = ans % mod;
}

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<vll> dp(n + 1, vll(k, -1));
    ll ans = lucy(1, 0, k, n, dp);

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