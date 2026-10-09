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

    vll v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(all(v));

    for (int ops = n; ops <= n + 30; ++ops)
    {
        int rem = n - max(0, ops - 30);
        priority_queue<int> pq;
        for (int i = 0; i < rem; ++i)
            pq.push(v[i]);

        for (int i = min(29, ops - 1); i >= 0; --i)
        {
            if (pq.empty())
                break;
            ll x = pq.top();
            pq.pop();
            x -= (1 << i);
            if (x > 0)
                pq.push(x);
        }
        if (pq.empty())
        {
            cout << ops << endl;
            return;
        }
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