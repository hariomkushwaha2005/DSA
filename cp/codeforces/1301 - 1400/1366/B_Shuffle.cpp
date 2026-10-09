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
    ll n, x, m;
    cin >> n >> x >> m;

    ll st = x, end = x;
    while (m--)
    {
        ll l, r;
        cin >> l >> r;

        if (r < st || l > end)
            continue;
        else
        {
            st = min(st, l);
            end = max(end, r);
        }
    }
    cout << end - st + 1 << endl;
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