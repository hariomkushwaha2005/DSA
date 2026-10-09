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
    ll x, a, b;
    cin >> x >> a >> b;

    ll ans;
    if (x < 80)
        ans = 20 * b + a * (80 - x);
    else
        ans = (100 - x) * b;

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