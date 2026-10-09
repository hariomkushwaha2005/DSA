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

void solve()
{
    ll n;
    cin >> n;

    unordered_map<ll, vll> mp;
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        mp[x].push_back(i + 1);
    }

    if (mp.size() == 1)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    bool found = 0;
    ll x;
    for (auto it : mp)
    {
        if (!found)
        {
            x = it.second[0];
            found = 1;
            continue;
        }
        for (auto z : it.second)
        {
            cout << x << " " << z << endl;
        }
        x = it.second[0];
    }
    bool chi = 1;
    for(auto it : (*mp.begin()).second){
        if(chi){
            chi = 0;
            continue;
        }
        cout << x << " " << it << endl;
    }
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