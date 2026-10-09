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
    ll x, y;
    cin >> x >> y;

    if (x <= y)
    {
        if (y & 1)
        {
            y *= y;
            cout << y + 1 - x << endl;
        }
        else
        {
            --y;
            y *= y;
            ++y;
            cout << y - 1 + x << endl;
        }
    }
    else
    {
        if (!(x & 1))
        {
            x *= x;
            cout << x + 1 - y << endl;
        }
        else
        {
            --x;
            x *= x;
            ++x;
            cout << x - 1 + y << endl;
        }
    }
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