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
    for (auto &it : v)
        cin >> it;

    ll maxi = LLONG_MIN, smax = LLONG_MIN;
    for (int i = 1; i < n; ++i)
    {
        ll x = abs(v[i] - v[i - 1]);
        if (x > maxi)
        {
            smax = maxi;
            maxi = x;
        }
        else
            smax = max(smax, x);
    }
    ll x = abs(v[0] - v[n - 1]);
    if (x > maxi)
    {
        smax = maxi;
        maxi = x;
    }
    else
        smax = max(smax, x);

    cout << smax << endl;
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