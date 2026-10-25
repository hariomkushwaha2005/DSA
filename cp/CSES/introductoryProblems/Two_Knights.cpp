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

ll maxx = 100000;
ll pre[100001];

void solve()
{
    ll n;
    cin >> n;

    for(int i = 1; i <= n; ++i) cout << pre[i] << endl;
}

int main()
{
    fast_io();
    for (ll i = 1; i < 100001; ++i)
    {
        pre[i] = ((i * i * i * i - 9 * i * i + 24 * i - 16) >> 1);
    }
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}