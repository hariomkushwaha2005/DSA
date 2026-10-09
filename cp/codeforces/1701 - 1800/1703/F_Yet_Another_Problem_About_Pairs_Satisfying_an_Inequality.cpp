#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

    ll cnt = 0;
    vector<pair<ll, ll>> v;
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        if (x < i + 1)
        {
            cnt += lower_bound(v.begin(), v.end(), x, [](const pair<ll, ll> &p, ll x)
                               { return x > p.first; }) -
                   v.begin();
            v.push_back({i + 1, x});
        }
    }
    cout << cnt << endl;
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