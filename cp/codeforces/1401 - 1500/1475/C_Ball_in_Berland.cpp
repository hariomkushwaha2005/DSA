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
    ll a, b, c;
    cin >> a >> b >> c;

    vll d(a + 1), e(b + 1), f(c), g(c);
    for (int i = 0; i < c; ++i)
    {
        cin >> f[i];
        d[f[i]]++;
    }
    for (int i = 0; i < c; ++i)
    {
        cin >> g[i];
        e[g[i]]++;
    }

    ll h = 0;
    for (int i = 0; i < c; ++i)
    {
        h += (c - d[f[i]] - e[g[i]] + 1);
    }
    cout << h / 2 << endl;
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