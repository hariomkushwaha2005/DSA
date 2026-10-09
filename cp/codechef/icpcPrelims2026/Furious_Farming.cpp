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

    vll v(m);
    for (auto &it : v)
        cin >> it;

    ranges::sort(v);
    ll a = v[0] - 1;
    ll b = n - v[m - 1];

    if (a > b)
        swap(a, b);

    ll c = 0;
    for (int i = 1; i < m; ++i)
        c = max(c, v[i] - v[i - 1] - 1);

    cout << 2 * a + b + max(0LL, c - a - b) << endl;
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