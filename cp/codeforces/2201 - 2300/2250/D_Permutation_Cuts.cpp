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
long long MOD = 998244353;

void solve()
{
    int n;
    cin >> n;

    vll v(n - 1);
    vector<int> mp(n + 1, 0);
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    if (mp[n])
    {
        cout << 0 << endl;
        return;
    }
    vector<int> st(n + 1, 0);
    int l = 0;
    while (l < n - 2 && v[l] <= v[l + 1] && v[l] < n - 1)
    {
        st[v[l]] = 1;
        ++l;
    }

    if (v[l] != n - 1)
    {
        cout << 0 << endl;
        return;
    }

    while (l < n - 1 && v[l] == n - 1)
        ++l;

    while (l < n - 1 && v[l] <= v[l - 1])
    {
        if (st[v[l]])
        {
            cout << 0 << endl;
            return;
        }
        l++;
    }
    if (l != n - 1)
    {
        cout << 0 << endl;
        return;
    }

    int free = 0;
    ll ans = 2;
    for (int i = n - 1; i > 0; --i)
    {
        if (mp[i] == 0)
        {
            ans = (ans * free) % MOD;
            free--;
            if (free < 0)
                break;
        }
        else
            free += (mp[i] - 1);
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