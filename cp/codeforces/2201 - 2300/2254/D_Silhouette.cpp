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

    vll b(n);
    map<ll, ll> mp;
    for (auto &x : b)
    {
        cin >> x;
        mp[x]++;
    }

    ll x = mp.size();
    vll c;
    for (auto it : mp)
        c.push_back(it.first);

    if(c[0] != 0){
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < x - 1; ++i)
    {
        ll last = i == 0 ? -1 : mp[c[i - 1]];
        ll avl = c[i + 1] - c[i];
        if (avl % mp[c[i]] != 0 || avl / mp[c[i]] <= last)
        {
            cout << -1 << endl;
            return;
        }
        else
            mp[c[i]] = avl / mp[c[i]];
    }

    mp[c[x - 1]] = (x == 1) ? 1 : mp[c[x - 2]] + 1;
    for (int i = 0; i < n; ++i)
        cout << mp[b[i]] << " ";

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