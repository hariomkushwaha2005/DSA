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
    ll n;
    cin >> n;

    vll a(n);
    ll zero = 0;
    for (auto &x : a)
    {
        cin >> x;
        zero += x;
    }
    zero = n - zero;

    vll b(n);
    ll one = 0;
    ll three = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
        one += b[i];
        if (a[i] && a[i] != b[i])
            three++;
    }

    if (a == b)
        cout << 0 << endl;
    else if (zero == n || one == n)
        cout << -1 << endl;
    else if (three & 1)
        cout << 1 << endl;
    else
        cout << 2 << endl;
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