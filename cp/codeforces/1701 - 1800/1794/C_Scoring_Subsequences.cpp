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
    int n;
    cin >> n;

    stack<pair<ll, int>> v;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        x += i;
        v.push({x, i});
    }

    vll ans(n);
    for (int i = n - 1; i >= 0; --i)
    {
        while (!v.empty() && v.top().first > i)
            v.pop();
        if (v.empty())
            ans[i] = i + 1;
        else
            ans[i] = i - v.top().second;
    }
    for(auto it : ans) cout << it << " ";

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