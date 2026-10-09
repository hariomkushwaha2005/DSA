#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

    vll v(n);
    ll maxx = INT_MIN;
    ll minn = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];

        if (i & 1)
            maxx = max(maxx, v[i]);
        else
            minn = min(minn, v[i]);
    }
    if ((n & 1) || (minn - 1 <= maxx))
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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