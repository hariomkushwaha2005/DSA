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
    ll n;
    cin >> n;

    vll v(n);
    for (auto &x : v)
        cin >> x;
    vll dp(n, 1);

    for (int i = n - 1; i >= 0; --i)
    {
        int j = 2 * i + 2;
        while (j <= n)
        {
            if (v[j - 1] > v[i])
            {
                dp[i] = max(dp[i], dp[j - 1] + 1);
            }
            j += i + 1;
        }
    }
    ll ans = 1;
    for (auto &x : dp)
        ans = max(ans, x);
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