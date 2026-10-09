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
    ll n, k;
    cin >> n >> k;

    vll v(n);
    for (auto &x : v)
        cin >> x;

    vll a(n, 0);
    ll d = 0;
    for (int i = 0; i < n; ++i)
    {
        a[i] = v[i] - d;
        d += k;
    }

    for (int i = 1; i < n; ++i)
        a[i] += a[i - 1];

    cout << 0 << " ";
    for (int i = 1; i < n - 1; ++i)
    {
        ll base = v[i - 1] + k, l = i, h = n - 1;
        while (l <= h)
        {
            ll mid = l + ((h - l) >> 1);
            ll val = v[mid] - base - (mid - i - 1) * k;
            if (val < 0)
                h = mid - 1;
            else
                l = mid + 1;
        }
        ll val = a[h] - a[i];
        val = val + (h - i) * ((i + 1) * k) - (h - i) * (base);
        cout << val << " ";
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