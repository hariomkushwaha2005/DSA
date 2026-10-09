#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

inline void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int mp[3999999] = {0};
int off = 199998;

void solve()
{
    // Your logic goes here
    int n;
    cin >> n;

    vi v(n);
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        v[i] = off + v[i] - i;

        ans += mp[v[i]];
        mp[v[i]]++;
    }
    for (int i = 0; i < n; ++i)
    {
        mp[v[i]] = 0;
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