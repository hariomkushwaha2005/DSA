#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

void solve()
{
    ll n, a, b;
    cin >> n >> a >> b;

    vll v;
    v.push_back(0);
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        v.push_back(x);
    }

    ll cost = 0;
    ll ans = LLONG_MAX;
    for (int i = n - 1; i >= 0; --i)
    {
        cost += b * (n - i) * (v[i + 1] - v[i]);
        ans = min(v[i] * (a + b) + cost, ans);
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}