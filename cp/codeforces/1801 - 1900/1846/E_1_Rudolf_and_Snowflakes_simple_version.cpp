#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

    for (ll i = 2; i * i + i + 1 <= n; ++i)
    {
        ll x = 1 + i + i * i;
        ll y = i * i * i;
        while (x <= n)
        {
            if (x == n)
            {
                cout << "YES" << endl;
                return;
            }
            x += y;
            y *= i;
        }
    }
    cout << "NO" << endl;
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