#include <bits/stdc++.h>
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

    vll v(n);
    for (auto &x : v)
        cin >> x;

    cout << gcd(v[0], v[n - 1]) << "\n";
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