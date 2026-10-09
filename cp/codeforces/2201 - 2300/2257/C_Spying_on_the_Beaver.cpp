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

    vll a(n - 1);
    for (auto &x : a)
        cin >> x;

    ll m;
    cin >> m;

    vll b(m);
    for (auto &x : b)
        cin >> x;

    sort(b.rbegin(), b.rend());

    cout << m - 1 << " ";
    bool beaver = 0;
    for (int i = 0; i < m - 1; ++i)
    {
        cout << b[i] << " ";
    }

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