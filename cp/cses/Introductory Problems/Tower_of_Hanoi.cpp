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

void trans(int n, int a, int b, int c)
{
    if (n == 1)
    {
        cout << a << " " << c << endl;
        return;
    }

    trans(n - 1, a, c, b);
    cout << a << " " << c << endl;
    trans(n - 1, b, a, c);
}

void solve()
{
    ll n;
    cin >> n;

    cout << (1 << n) - 1 << endl;
    trans(n, 1, 2, 3);
}

int main()
{
    fast_io();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}