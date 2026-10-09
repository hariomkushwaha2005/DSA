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

    vll v(n);
    for (auto &x : v)
        cin >> x;

    vll u(n + 1, 0);
    int j = 0;
    ll x;
    ll cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        while (u[v[j]])
            ++j;

        cin >> x;

        if (x == v[j])
            j++;
        else
            cnt++;

        u[x] = 1;
    }
    cout << cnt << endl;
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