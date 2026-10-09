#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

inline void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    vll v(n);
    for (auto &x : v)
        cin >> x;

    vll a(n);
    a[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; --i)
        a[i] = max(a[i + 1], v[i]);

    ll val = 0;
    ll ans = LLONG_MIN;
    priority_queue<ll> pq;
    for (int i = 0; i < m - 1; ++i)
    {
        val -= v[i];
        pq.push(v[i]);
    }
    for (int i = m - 1; i < n; ++i)
    {
        ans = max(ans, val + m * a[i]);
        val -= v[i];
        pq.push(v[i]);
        val += pq.top();
        pq.pop();
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