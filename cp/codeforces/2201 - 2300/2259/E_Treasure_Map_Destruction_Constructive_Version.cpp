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

    vll v(n);
    for (auto &x : v)
        cin >> x;

    vll a(n, 0);
    ll val = 0;
    for (int i = 0; i < n; ++i)
    {
        val = max(val, v[i]);
        if (val > 0)
            a[i] = val;
        --val;
    }
    val = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        val = max(val, a[i]);
        if (val > 0)
            a[i] = val;
        --val;
    }

    ll last = -1e9;
    vll dist(n, 1e9);
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 0)
            last = i;
        dist[i] = min(dist[i], i - last);
    }
    last = 1e9;
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] == 0)
            last = i;
        dist[i] = min(dist[i], last - i);
    }
    for (int i = 0; i < n; ++i)
    {
        if (v[i] != -1 && v[i] != dist[i])
        {
            cout << -1 << endl;
            return;
        }
    }
    for (auto &x : a)
        cout << (x == 0);
    cout << endl;
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