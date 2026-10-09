#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

inline void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    // Your logic goes here
    ll n, x, y;
    cin >> n >> x >> y;

    vll a(n);
    bool sorted = 1;
    ll last = 0;
    ll minn = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (last > a[i])
            sorted = false;
        last = a[i];
    }
    if (sorted)
    {
        cout << "YES" << endl;
        return;
    }
    ll z = __gcd(x, y);
    for (int i = 0; i < n; ++i)
    {
        if (abs(a[i] - 1 - i) % z != 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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