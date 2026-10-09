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
    ll n, c;
    cin >> n >> c;

    vll p(n);
    for (auto &i : p)
    {
        cin >> i;
        --i;
    }

    vll a(n);
    for (auto &i : a)
        cin >> i;

    vll v(n, 0);
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!v[i])
        {
            ll j = i;
            ll sum = a[j];
            ll val = max(0LL, a[j] - c);
            ll cnt = 1;
            v[j] = 1;
            while (p[j] != i)
            {
                j = p[j];
                sum += a[j];
                val += max(0LL, a[j] - c);
                cnt++;
                v[j] = 1;
            }
            ans += max(val, sum - (cnt - 1) * c);
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