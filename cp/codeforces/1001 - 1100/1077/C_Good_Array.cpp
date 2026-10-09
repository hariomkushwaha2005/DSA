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
    ll n;
    cin >> n;

    ll sum = 0;
    ll maxx = 0;
    ll smaxx = 0;
    vll v(n);

    for (auto &x : v)
    {
        cin >> x;
        sum += x;
        if (maxx < x)
        {
            smaxx = maxx;
            maxx = x;
        }
        else if (smaxx < x)
            smaxx = x;
    }

    vll a;
    for (int i = 0; i < n; ++i)
    {
        if (v[i] == maxx)
        {
            if (sum == (smaxx << 1) + maxx)
                a.push_back(i + 1);
            continue;
        }
        else
        {
            if (sum - v[i] == (maxx << 1))
                a.push_back(i + 1);
        }
    }

    cout << a.size() << endl;
    for (auto i : a)
        cout << i << " ";
    cout << endl;
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