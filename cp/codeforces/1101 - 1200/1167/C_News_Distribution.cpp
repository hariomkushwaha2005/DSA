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
    ll n, m;
    cin >> n >> m;

    vector<vll> adj(n + 1);
    while (m--)
    {
        ll a;
        cin >> a;
        ll y;
        if (a > 0)
        {
            --a;
            cin >> y;
        }
        while (a--)
        {
            ll x;
            cin >> x;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }
    vll v(n + 1, 0);
    queue<ll> q;
    for (int i = 1; i <= n; ++i)
    {
        if (v[i] == 0)
        {
            q.push(i);
            v[i] = i;
            while (!q.empty())
            {
                ll a = q.front();
                q.pop();
                for (auto it : adj[a])
                {
                    if (v[it] == 0)
                    {
                        v[it] = i;
                        q.push(it);
                    }
                }
            }
        }
    }
    vll b(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        b[v[i]]++;
    for (int i = 1; i <= n; ++i)
        cout << b[v[i]] << " ";
    cout << endl;
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