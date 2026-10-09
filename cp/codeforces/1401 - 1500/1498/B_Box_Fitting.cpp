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
    ll n, w;
    cin >> n >> w;

    vll v(n);
    for (auto &x : v)
        cin >> x;

    sort(v.rbegin(), v.rend());
    priority_queue<ll> pq;
    pq.push(w);
    for (auto i : v)
    {
        if (pq.top() < i)
            pq.push(w - i);
        else
        {
            ll x = pq.top();
            pq.pop();
            pq.push(x - i);
        }
    }

    cout << pq.size() << endl;
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