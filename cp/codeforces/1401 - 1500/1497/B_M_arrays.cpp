#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

inline void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    vll a(m, 0);
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        a[x % m]++;
    }

    ll ans = 0;
    
    if (a[0] > 0)
        ans++;

    int i = 1;
    while (i <= (m >> 1))
    {
        ll b = max(a[i], a[m - i]);
        ll c = min(a[i], a[m - i]);

        if (b > 0)
            ans += max(b - c, 1LL);

        i++;
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