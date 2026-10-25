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
    ll n, m;
    cin >> n >> m;

    vector<string> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            vector<int> vis(4, 0);
            vis[v[i][j] - 'A'] = 1;
            if (i > 0)
                vis[v[i - 1][j] - 'A'] = 1;
            if (j > 0)
                vis[v[i][j - 1] - 'A'] = 1;
            for (int k = 0; k < 4; ++k)
            {
                if (!vis[k])
                {
                    v[i][j] = 'A' + k;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cout << v[i][j];
        cout << endl;
    }
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