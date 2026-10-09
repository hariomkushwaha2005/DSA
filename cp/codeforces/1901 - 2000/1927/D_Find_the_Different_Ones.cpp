#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

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

    vll pre(n);
    pre[0] = -1;

    for (int i = 1; i < n; ++i)
    {
        if (v[i] == v[i - 1])
            pre[i] = pre[i - 1];
        else
            pre[i] = i - 1;
    }

    ll q;
    cin >> q;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;

        l--;
        r--;
        if (pre[r] < l)
            cout << -1 << " " << -1 << endl;
        else
            cout << pre[r] + 1 << " " << r + 1 << endl;
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
        cout << endl;
    }

    return 0;
}