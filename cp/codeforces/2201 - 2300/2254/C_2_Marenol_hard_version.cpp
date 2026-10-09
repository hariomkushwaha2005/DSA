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

    string s, t;
    cin >> s >> t;

    if (s == t)
    {
        cout << 0 << endl;
        return;
    }

    if (n < 3)
    {
        cout << -1 << endl;
        return;
    }

    ll i = 0;
    vector<pair<int, int>> v;
    ll ans = 0;
    for (; i < n; i += 2)
    {
        if (s[i] != t[i])
        {
            if (!v.empty() && v.back().first != s[i])
            {
                ans += (i - v.back().second) / 2;
                v.pop_back();
            }
            else
                v.push_back({s[i], i});
        }
    }
    if (!v.empty())
    {
        cout << -1 << endl;
        return;
    }
    i = 1;
    for (; i < n; i += 2)
    {
        if (s[i] != t[i])
        {
            if (!v.empty() && v.back().first != s[i])
            {
                ans += (i - v.back().second) / 2;
                v.pop_back();
            }
            else
                v.push_back({s[i], i});
        }
    }
    if (!v.empty())
    {
        cout << -1 << endl;
        return;
    }

    cout << ans << endl;
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