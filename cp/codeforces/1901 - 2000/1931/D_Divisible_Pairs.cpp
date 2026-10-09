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
    ll n, x, y;
    cin >> n >> x >> y;

    map<pair<ll, ll>, ll> pre;
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ll a;
        cin >> a;

        ll b = a % x;
        ll c = a % y;
        ans += pre[{(x - b) % x, c}];
        pre[{b, c}]++;
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