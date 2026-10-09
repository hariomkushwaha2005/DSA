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

    vll a(n);
    for (auto &x : a)
        cin >> x;

    vll b(m);
    for (auto &x : b)
        cin >> x;

    sort(all(b));

    vll pre(n + 1);
    pre[0] = 0;

    for (int i = 0; i < n; ++i)
        pre[i + 1] = pre[i] + a[i];

    ll ans = abs(pre[b[0]]);
    for (int i = 1; i < m; ++i)
    {
        ll cur = pre[b[i]] - pre[b[i - 1]];
        ans += abs(cur);
    }
    ans += pre[n] - pre[b[m - 1]];
    ans = max(ans, pre[n]);
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