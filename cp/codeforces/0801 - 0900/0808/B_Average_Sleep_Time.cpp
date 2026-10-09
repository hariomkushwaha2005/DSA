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
    ll n, k;
    cin >> n >> k;

    ll sum = 0;
    vll v(n);
    for (int i = 0; i < k; ++i)
    {
        cin >> v[i];
        sum += v[i];
    }

    ll j = 0;
    ll tot = sum;
    for (int i = k; i < n; ++i, j++)
    {
        cin >> v[i];
        sum = sum + v[i] - v[j];
        tot += sum;
    }

    cout << fixed << setprecision(6) << (double)tot / (n - k + 1) << endl;
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