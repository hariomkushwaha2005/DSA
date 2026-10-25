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

    ll cnt = 0;
    vll v(n);
    for (auto &i : v)
    {
        cin >> i;
        if (i == 1)
            cnt++;
    }

    if (cnt > 0)
    {
        cout << n - cnt << endl;
        return;
    }

    ll val = 1e9;
    for (ll i = 0; i < n; ++i)
    {
        ll gc = v[i];
        for (ll j = i + 1; j < n; ++j)
        {
            gc = gcd(gc, v[j]);
            if (gc == 1)
            {
                val = min(val, j - i);
                break;
            }
        }
    }

    if (val == 1e9)
        cout << -1 << endl;
    else
        cout << val + n - 1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}