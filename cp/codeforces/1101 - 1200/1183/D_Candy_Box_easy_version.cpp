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
    ll n;
    cin >> n;

    vll v(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        v[x]++;
    }
    ranges::sort(v);
    ranges::reverse(v);

    ll last = INT_MAX;
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        last = min(last - 1, v[i]);
        if (last <= 0)
            break;
        ans += last;
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