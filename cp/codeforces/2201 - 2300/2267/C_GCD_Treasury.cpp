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
    ll n, x;
    cin >> n >> x;

    vll v(n);
    for (auto &i : v)
        cin >> i;

    map<ll, ll> a;
    for (auto b : v)
    {
        ll g = __gcd(b, x);
        if (g != 1)
        {
            if (!(g & 1))
            {
                while (!(g & 1))
                    g >>= 1;
                a[2] += b;
            }
            for (int i = 3; i * i <= g; i += 2)
            {
                if (g % i == 0)
                {
                    a[i] += b;
                    while (g % i == 0)
                        g /= i;
                }
            }
            if (g > 1)
            {
                a[g] += b;
            }
        }
    }

    ll ans = 0;
    for (auto [y, z] : a)
        ans = max(ans, z);

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