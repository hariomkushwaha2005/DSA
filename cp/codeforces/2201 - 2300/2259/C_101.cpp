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

    vll v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    ll i = 0;
    while (i < n && v[i] == 0)
    {
        ++i;
    }
    if (i < n && v[i] == -1)
        v[i] = 1;
    i = n - 1;
    while (i >= 0 && v[i] == 0)
    {
        --i;
    }
    if (i >= 0 && v[i] == -1)
        v[i] = 1;

    for (auto &x : v)
        cout << (x == -1 ? 0 : x) << " ";
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