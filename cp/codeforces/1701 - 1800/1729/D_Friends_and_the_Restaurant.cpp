#pragma GCC optimize("O3,unroll-loops")

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
    // Your logic goes here
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (auto &it : v)
    {
        cin >> it.first;
    }
    for (auto &it : v)
    {
        cin >> it.second;
    }

    sort(v.begin(), v.end(), [](const auto &a, const auto &b)
         { return (a.first - a.second) > (b.first - b.second); });

    int cnt = 0;
    int l = 0, r = n - 1;
    while (l < r)
    {
        if ((v[l].second - v[l].first) + (v[r].second - v[r].first) >= 0){
            cnt++;
            l++;
            r--;
        }
        else{
            l++;
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