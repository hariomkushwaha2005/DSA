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
ll mod = 1e9 + 7;
ll pre[1000001];

void solve()
{
    ll n;
    cin >> n;

    cout << pre[n] << endl;
}

int main()
{
    fast_io();
    pre[0] = 1;
    for (int i = 1; i < 1000001; ++i)
        pre[i] = (pre[i - 1] << 1) % mod;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}