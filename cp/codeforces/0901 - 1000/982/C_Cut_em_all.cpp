#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

ll dfs(ll node, ll &cnt, vll &vis, vector<vll> &adj)
{
    vis[node] = 1;
    ll res = 1;
    for (auto i : adj[node])
    {
        if (!vis[i])
            res += dfs(i, cnt, vis, adj);
    }
    if (!(res & 1))
        cnt++;
    return res;
}

void solve()
{
    ll n;
    cin >> n;

    if (n & 1)
    {
        cout << -1 << endl;
        return;
    }

    vector<vll> adj(n + 1);
    for (int i = 1; i < n; ++i)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vll vis(n + 1, 0);
    ll cnt = 0;

    dfs(1, cnt, vis, adj);
    cout << cnt - 1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}