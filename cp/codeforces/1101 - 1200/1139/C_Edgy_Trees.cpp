#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

ll mod = 1e9 + 7;

ll power(ll n, ll k)
{
    n %= mod;
    ll res = 1;
    while (k > 0)
    {
        if (k & 1)
            res = res * n % mod;
        n = n * n % mod;
        k >>= 1;
    }
    return res;
}

ll bfs(ll j, vll &vis, vector<vector<array<ll, 2>>> &adj)
{
    queue<ll> q;
    vis[j] = 1;
    q.push(j);
    ll cnt = 0;
    while (!q.empty())
    {
        ll a = q.front();
        q.pop();
        cnt++;
        for (auto i : adj[a])
        {
            if (!i[1] && !vis[i[0]])
            {
                vis[i[0]] = 1;
                q.push(i[0]);
            }
        }
    }
    return cnt;
}

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<vector<array<ll, 2>>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        ll x, y, z;
        cin >> x >> y >> z;

        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    ll ans = power(n, k);
    vll vis(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            ll a = bfs(i, vis, adj);
            ans -= power(a, k);
            ans = (ans + mod) % mod;
        }
    }
    cout << ans << endl;
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