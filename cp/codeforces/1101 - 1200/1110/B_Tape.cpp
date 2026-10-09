#include <bits/stdc++.h>
#define endl '\n'

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
    ll n, m, k;
    cin >> n >> m >> k;

    if (k >= n)
    {
        cout << n << endl;
    }
    else
    {
        vll v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];

        ll val = v[n - 1] - v[0] + 1;

        vll a(n - 1);
        for (int i = 0; i < n - 1; ++i)
            a.push_back(v[i + 1] - v[i] - 1);

        sort(a.begin(), a.end(), greater<ll>());
        for (int i = 0; i < k - 1; ++i)
            val -= a[i];

        cout << val << endl;
    }
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