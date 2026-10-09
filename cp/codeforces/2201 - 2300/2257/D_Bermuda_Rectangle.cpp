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
    ll s, q;
    cin >> s >> q;

    vll v;
    for (ll i = 1; i * i <= s; ++i)
    {
        if (s % i == 0)
        {
            v.push_back(i);
            if (i != (s / i))
                v.push_back(s / i);
        }
    }

    sort(all(v));
    int n = v.size();

    vll pre(n, 0);
    pre[0] = s;
    for (ll i = 1; i < n; ++i)
        pre[i] = pre[i - 1] + (v[i] - v[i - 1]) * (s / v[i]);

    while (q--)
    {
        ll x, y;
        cin >> x >> y;

        ll val = 0;
        ll a = s / y;
        auto it = upper_bound(all(v), a);
        val += min(x, *(it - 1)) * y;

        if (*(it - 1) < x)
        {
            auto it2 = upper_bound(all(v), x);
            val += pre[it2 - 1 - v.begin()] - pre[(it - 1 - v.begin())];

            if (it2 != v.end())
                val += (x - *(it2 - 1)) * (s / *it2);
        }

        cout << val << endl;
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
    }

    return 0;
}