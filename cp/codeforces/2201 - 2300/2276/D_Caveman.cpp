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

    vll adj(n, 0);
    for (int i = 0; i < m; ++i)
    {
        ll x, y;
        cin >> x >> y;
        adj[x - 1]++;
        adj[y - 1]++;
    }

    ll maxx = 0;
    for (int i = 0; i < n; ++i)
    {
        if (adj[i] == 0)
        {
            cout << "Brain Melt" << endl;
            return;
        }
        maxx = max(adj[i], maxx);
    }

    if (maxx == n - 1 && m == n - 1)
        cout << 2 << endl;
    else
        cout << "Many" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}