#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

void solve()
{
    ll n, m;
    cin >> n >> m;

    vector<vll> adj(n + 1);
    for (int i = 0; i < m; ++i)
    {
        ll x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vll vis(n + 1, 0);
    priority_queue<ll, vll, greater<>> pq;
    pq.push(1);
    vis[1] = 1;
    while (!pq.empty())
    {
        ll a = pq.top();
        pq.pop();
        cout << a << " ";
        for (auto v : adj[a])
        {
            if (!vis[v])
            {
                pq.push(v);
                vis[v] = 1;
            }
        }
    }
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