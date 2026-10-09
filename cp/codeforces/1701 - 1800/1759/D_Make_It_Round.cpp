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

    ll a = n;
    ll t = 0;
    while (a % 2 == 0)
    {
        a /= 2;
        ++t;
    }

    a = n;
    ll f = 0;
    while (a % 5 == 0)
    {
        a /= 5;
        ++f;
    }

    a = max(t, f);
    t = a - t;
    f = a - f;

    a = 1;
    for (int i = 0; i < t && a * 2 <= m; ++i)
        a *= 2;
    for (int i = 0; i < f && a * 5 <= m; ++i)
        a *= 5;

    while (a * 10 <= m)
        a *= 10;

    a = m / a * a;

    cout << n * a << endl;
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