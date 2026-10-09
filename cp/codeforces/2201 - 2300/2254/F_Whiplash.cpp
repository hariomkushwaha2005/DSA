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

    ll axor = 0;
    vll a(n + 1);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        axor ^= a[i];
    }

    ll bxor = 0;
    vll b(n + 1);
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
        bxor ^= b[i];
    }

    for (int i = 0; i < n; ++i)
    {
        a[i] ^= axor;
        b[i] ^= bxor;
    }

    a[n] = axor;
    b[n] = bxor;

    sort(all(a));
    sort(all(b));

    if (a == b)
        cout << "YES" << endl;
    else
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