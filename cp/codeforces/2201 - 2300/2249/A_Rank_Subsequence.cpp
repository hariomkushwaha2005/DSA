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

    vector<array<ll, 4>> v(n + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> v[i][j];

    for (int i = n; i >= 0; --i)
    {
        int rank = 1;
        for (int j = 1; j <= n; ++j)
            if (((rank < v[j][0]) || (rank > v[j][1])) &&
                (((i + 1 - rank) < v[j][2]) || ((i + 1 - rank) > v[j][3])))
                rank++;

        if (rank >= i + 1)
        {
            cout << i << endl;
            return;
        }
    }
    cout << 0 << endl;
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