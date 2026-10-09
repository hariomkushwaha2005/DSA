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
    ll a, b;
    cin >> a >> b;

    if (a > b)
        swap(a, b);

    ll sub = b - a;
    a -= sub;
    b -= (sub << 1);

    if (a >= 0 && b >= 0 && a % 3 == 0 && b % 3 == 0)
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