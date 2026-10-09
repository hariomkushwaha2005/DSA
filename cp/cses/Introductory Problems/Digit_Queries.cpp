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

void solve()
{
    ll n;
    cin >> n;

    ll a = 1;
    ll b = 1;
    ll c = 9;

    while (n > c * b)
    {
        n -= c * b;
        c *= 10;
        a *= 10;
        b++;
    }
    a += (n - 1) / b;
    ll d = (n - 1) % b;
    d = b - d;
    ll ld;
    while (d > 0)
    {
        --d;
        ld = a % 10;
        a /= 10;
    }
    cout << ld << endl;
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