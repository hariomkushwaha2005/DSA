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
    ll x, y;
    cin >> x >> y;

    if (!(x & y))
    {
        cout << x + y << " " << 0 << endl;
        return;
    }
    ll a = 1;
    ll val = 0;
    ll c = 0;
    while (a <= x && a <= y)
    {
        if (a & x & y)
        {
            ll b = a & x & y;
            val += (b - c);
            x -= (b - c);
            y += (b - c);
            c = 0;
        }
        else if (a & y)
        {
            ll b = a & y;
            c += b;
        }
        a <<= 1;
    }
    cout << x + y << " " << val << endl;
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