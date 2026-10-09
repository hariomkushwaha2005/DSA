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

    vll a(n);
    for(auto &x : a) cin >> x;

    vll b(m);
    for(auto &x : b) cin >> x;

    ll c = a[0] + n - 1;
    ll d = b[0] + m - 1;

    if(c >= d) cout << 1 << endl;
    else cout << 2 << endl;
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