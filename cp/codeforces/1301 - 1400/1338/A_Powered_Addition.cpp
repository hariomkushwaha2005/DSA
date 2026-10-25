#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

void solve()
{
    ll n;
    cin >> n;

    ll x = -1e9;
    ll val = 0;
    for (int i = 0; i < n; ++i)
    {
        ll y;
        cin >> y;

        x = max(x, y);
        val = max(val, x - y);
    }

    if (!val)
        cout << 0 << endl;
    else
        cout << 32 - __builtin_clz(val) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}