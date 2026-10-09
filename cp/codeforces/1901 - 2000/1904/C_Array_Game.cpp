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
    ll n, k;
    cin >> n >> k;

    vll v(n);
    ll ans = LLONG_MAX;
    for (auto &x : v)
    {
        cin >> x;
        ans = min(ans, x);
    }

    sort(all(v));

    if (k > 2)
    {
        cout << 0 << endl;
        return;
    }

    for (int i = 1; i < n; ++i)
        ans = min(ans, v[i] - v[i - 1]);

    if (k == 1 || ans == 0)
    {
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            ll x = v[j] - v[i];
            auto it = lower_bound(v.begin(), v.end(), x);
            if (it != v.end())
                ans = min(ans, *it - x);
            if (it != v.begin())
            {
                --it;
                ans = min(ans, x - *it);
            }
            if (ans == 0)
            {
                cout << 0 << endl;
                return;
            }
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