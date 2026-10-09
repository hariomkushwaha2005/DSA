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
    ll n;
    cin >> n;

    ll o = 0, ee = 0, eo = 0;
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        if (x & 1)
            o++;
        else if ((x >> 1) & 1)
            eo++;
        else
            ee++;
    }
    cout << max(o, max(ee, eo)) << endl;
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