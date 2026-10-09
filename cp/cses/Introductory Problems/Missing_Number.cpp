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

    ll xorr;
    if (n % 4 == 0)
        xorr = n;
    else if (n % 4 == 1)
        xorr = 1;
    else if (n % 4 == 2)
        xorr = n + 1;
    else
        xorr = 0;

    for (int i = 1; i < n; ++i)
    {
        ll x;
        cin >> x;

        xorr ^= x;
    }

    cout << xorr << endl;
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