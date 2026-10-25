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

    vll v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    ll a = 0;
    ll c = 0;
    map<pair<ll, ll>, ll> mp;
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;

        if (v[i] == 0)
        {
            if (x == 0)
                c++;
        }
        else if (x == 0)
        {
            mp[{0, 0}]++;
            a = max(a, mp[{0, 0}]);
        }
        else
        {
            ll b = gcd(v[i], x);
            v[i] /= b;
            x /= b;
            ll sign = 1;
            if (v[i] * x < 0)
                sign = -1;
            mp[{sign * abs(v[i]), abs(x)}]++;
            a = max(a, mp[{sign * abs(v[i]), abs(x)}]);
        }
    }
    cout << a + c << endl;
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