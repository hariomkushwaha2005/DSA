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

struct p
{
    ll a;
    ll b;
};

p help(ll n)
{
    for (ll i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            if (i & 1)
            {
                p c = help(i);
                return {c.a * (n / i), c.b * (n / i)};
            }
            else
            {
                return {(n / i) * (i >> 1), (n / i) * (i >> 1)};
            }
        }
    }
    return {1, n - 1};
}

void solve()
{
    ll n;
    cin >> n;

    if (n & 1)
    {
        p c = help(n);
        cout << c.a << " " << c.b << " " << endl;
        return;
    }
    cout << (n >> 1) << " " << (n >> 1) << endl;
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