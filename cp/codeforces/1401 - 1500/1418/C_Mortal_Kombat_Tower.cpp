#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

ll help(ll i, vll &v, vll &dp)
{
    if (i >= v.size())
        return 0;

    if (dp[i] != -1)
        return dp[i];

    ll a = (v[i] + min(help(i + 2, v, dp), help(i + 3, v, dp)));
    if (i + 1 < v.size())
        a = min(a, v[i] + v[i + 1] + min(help(i + 3, v, dp), help(i + 4, v, dp)));

    return dp[i] = a;
}

void solve()
{
    ll n;
    cin >> n;

    vll v(n);
    for (auto &i : v)
        cin >> i;

    vll dp(n, -1);
    cout << help(0, v, dp) << endl;
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