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

    vector<pair<ll, ll>> v(n);

    for (int i = 0; i < n; ++i)
    {
        ll k;
        cin >> k;
        ll st = 0;
        for (int j = 0; j < k; ++j)
        {
            ll x;
            cin >> x;
            if (st + j <= x)
                st = x + 1 - j;
        }
        v[i] = {st, k};
    }

    sort(all(v));
    ll st = 0, inc = 0;
    for (auto it : v)
    {
        if (st + inc < it.first)
            st = it.first - inc;
        inc += it.second;
    }
    cout << st << endl;
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