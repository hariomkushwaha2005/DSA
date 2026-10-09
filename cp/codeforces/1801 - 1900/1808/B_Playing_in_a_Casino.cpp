#pragma GCC optimize("O3,unroll-loops")

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
    // Your logic goes here
    int n, m;
    cin >> n >> m;

    vector<vi> v(m, vi(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[j][i];
        }
    }
    for (int i = 0; i < m; i++){
        sort(all(v[i]));
    }

    ll ans = 0;
    for (int i = 0; i < m; i++){
        int l = 0, r = n - 1;
        while (l < r)
        {
            ans += (ll)(v[i][r] - v[i][l]) * (r - l);
            r--;
            l++;
        }
    }
    cout << ans << endl;
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