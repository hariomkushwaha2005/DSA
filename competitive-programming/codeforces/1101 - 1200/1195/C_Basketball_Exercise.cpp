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
    ll n;
    cin >> n;

    vll a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;

    if (n > 1)
    {
        a[n - 2] += b[n - 1];
        b[n - 2] += a[n - 1];
    }

    for (int i = n - 3; i >= 0; --i)
    {
        a[i] += max(b[i + 1], b[i + 2]);
        b[i] += max(a[i + 1], a[i + 2]);
    }
    cout << max(a[0], b[0]) << endl;
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