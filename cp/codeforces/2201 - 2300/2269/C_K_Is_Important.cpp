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
    ll n, k;
    cin >> n >> k;

    vll v(n);
    for (auto &x : v)
        cin >> x;

    ll val = 0;
    ll l = k - 1, r = n - k;
    vll vis(n, 0);
    ll took = 0;
    for (int i = 0; i < n - 2 * k + 2; ++i)
    {
        while (vis[l])
            ++l;
        while (vis[r])
            --r;

        if (l < n && v[l] > v[r])
        {
            vis[l] = 1;
            val += v[l];
        }
        else
        {
            vis[r] = 1;
            val += v[r];
        }
        took++;
    }
    ll z = n - took - k + 1;
    for (int i = 0; i < z; ++i)
    {
        while (vis[l])
            ++l;
        while (vis[r])
            --r;

        if (l < n && v[l] > v[r])
        {
            vis[l] = 1;
            val += v[l];
            ++l, --r;
        }
        else
        {
            vis[r] = 1;
            val += v[r];
            ++l, --r;
        }
    }

    cout << val << endl;
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