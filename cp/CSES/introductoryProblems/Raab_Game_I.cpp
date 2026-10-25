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
    ll n, a, b;
    cin >> n >> a >> b;

    if (a + b > n || (a > 0 && b == 0) || (b > 0 && a == 0))
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    ll base = n - a - b;

    for (int i = 1; i <= base; ++i)
        cout << i << " ";
    for (int i = 1; i <= a; ++i)
        cout << base + b + i << " ";
    for (int i = 1; i <= b; ++i)
        cout << base + i << " ";
    cout << endl;

    for (int i = 1; i <= n; ++i)
        cout << i << " ";
    cout << endl;
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