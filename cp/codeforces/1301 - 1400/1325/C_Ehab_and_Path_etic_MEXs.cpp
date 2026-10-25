#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

void solve()
{
    ll n;
    cin >> n;

    vector<vll> adj(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        ll x, y;
        cin >> x >> y;

        adj[x].push_back(i);
        adj[y].push_back(i);
    }

    ll j = 0;
    vll v(n - 1, -1);
    for (int i = 1; i <= n; ++i)
    {
        if (adj[i].size() == 1 && v[adj[i][0]] == -1)
            v[adj[i][0]] = j++;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        if (v[i] == -1)
            v[i] = j++;
        cout << v[i] << endl;
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