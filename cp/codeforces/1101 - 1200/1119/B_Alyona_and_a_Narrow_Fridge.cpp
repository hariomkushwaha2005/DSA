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
    ll n, h;
    cin >> n >> h;

    vll v(n);
    for(auto &x : v) cin >> x;

    for (int i = 0; i < n; ++i)
    {
        ll j = i;
        while (j > 0 && v[j - 1] > v[j])
        {
            swap(v[j - 1], v[j]);
            j--;
        }

        ll sum = 0;
        j = i;
        while (j >= 0)
        {
            sum += v[j];
            j -= 2;
        }
        if (sum > h)
        {
            cout << i << endl;
            return;
        }
    }
    cout << n << endl;
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