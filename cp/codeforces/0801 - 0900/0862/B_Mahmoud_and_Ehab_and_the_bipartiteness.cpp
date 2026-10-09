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

void solve()
{
    ll n;
    cin >> n;

    vector<vi> v(n);
    for (int i = 1; i < n; ++i)
    {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    vi vis(n, 0);
    queue<int> q;
    q.push(0);
    bool a = 0;
    ll b = 0, c = 0;
    while (!q.empty())
    {
        int size = q.size();

        if (a)
            b += size;
        else
            c += size;
        a = !a;

        while (size--)
        {
            int node = q.front();
            q.pop();
            vis[node] = 1;
            for (auto it : v[node])
            {
                if (!vis[it])
                    q.push(it);
            }
        }
    }
    cout << b*c - n + 1 << endl;
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