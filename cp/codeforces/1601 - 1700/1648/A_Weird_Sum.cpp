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
    vector<vll> x(100001);
    vector<vll> y(100001);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            ll z;
            cin >> z;
            x[z].push_back(i);
            y[z].push_back(j);
        }
    }
    ll tot = 0;
    for (int i = 0; i < 100001; ++i)
    {
        sort(all(x[i]));
        ll last = 0;
        for (int j = 1; j < (int)x[i].size(); ++j)
        {
            ll cur = last + (x[i][j] - x[i][j - 1]) * j;
            tot += cur;
            last = cur;
        }
        sort(all(y[i]));
        last = 0;
        for (int j = 1; j < (int)y[i].size(); ++j)
        {
            ll cur = last + (y[i][j] - y[i][j - 1]) * j;
            tot += cur;
            last = cur;
        }
    }
    cout << tot << endl;
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