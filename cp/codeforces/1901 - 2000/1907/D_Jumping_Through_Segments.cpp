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

    vll a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];

    ll l = 0, h = 1000000000;

    while (l <= h)
    {
        ll mid = l + ((h - l) >> 1);
        ll st = 0, end = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((st > b[i] && b[i] < st - mid) || (a[i] > end && end + mid < a[i]))
            {
                l = mid + 1;
                break;
            }
            else
            {
                st = max(st - mid, a[i]);
                end = min(end + mid, b[i]);
            }
        }
        if (l <= mid)
            h = mid - 1;
    }
    cout << l << endl;
}

int main()
{
    fast_io();

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}