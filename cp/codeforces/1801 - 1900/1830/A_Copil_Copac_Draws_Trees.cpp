#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

inline void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

ll dfs(int x, int p, vll &id, vector<vector<pair<ll, ll>>> &adj)
{
    ll z = 1;
    for (auto [y, idx] : adj[x])
    {
        if (y == p)
            continue;

        id[y] = idx;
        ll w = dfs(y, x, id, adj);

        if (id[x] > idx)
            w++;
            
        z = max(z, w);
    }
    return z;
}

void solve()
{
    ll n;
    cin >> n;

    vll id(n + 1);
    id[1] = 0;

    vector<vector<pair<ll, ll>>> adj(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        ll x, y;
        cin >> x >> y;

        adj[x].push_back({y, i});
        adj[y].push_back({x, i});
    }

    cout << dfs(1, -1, id, adj) << endl;
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