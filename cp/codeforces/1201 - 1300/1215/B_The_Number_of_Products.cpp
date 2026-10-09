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

    vll v;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        cnt++;
        if (x < 0)
        {
            v.push_back(cnt);
            cnt = 0;
        }
    }

    vll a;
    for (int i = 1; i < v.size(); ++i)
        a.push_back(v[i]);
    a.push_back(cnt + 1);

    ll ans = 0;
    ll cur = 0;
    for (int i = 0; i < v.size(); i += 2)
    {
        cur += v[i];
        ans += cur * a[i];
    }
    cur = 0;
    for (int i = 1; i < v.size(); i += 2)
    {
        cur += v[i];
        ans += cur * a[i];
    }
    cout << ans << " " << ((n * (n + 1) >> 1) - ans);
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