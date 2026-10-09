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
    {
        cin >> x;
        --x;
    }

    vector<vll> adj(n);
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        adj[v[i]].push_back(x);
    }

    for (int i = 0; i < n; ++i)
    {
        ranges::sort(adj[i], greater{});
        for (int j = 1; j < adj[i].size(); ++j)
            adj[i][j] += adj[i][j - 1];
    }

    vll ans(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        ll sz = adj[i].size();
        for (int j = 1; j <= sz; ++j)
        {
            ll a = sz - sz % j - 1;
            if (a >= 0)
                ans[j] += adj[i][a];
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
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