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

ll help(ll i, ll a, ll cnt, ll k, vll &b, vector<vll> &dp)
{
    if (a / cnt <= k)
        return 0;

    if (i >= b.size())
        return 1e9;

    if (dp[i][cnt] != -1)
        return dp[i][cnt];

    return dp[i][cnt] = min(help(i + 1, a, cnt, k, b, dp), cnt + help(i + 1, a, cnt * b[i], k, b, dp));
}

const ll maxn = 200001;
vll prime[maxn];

void precompute()
{
    for (int i = 2; i < maxn; ++i)
    {
        if (prime[i].empty())
        {
            for (int j = i; j < maxn; j += i)
                prime[j].push_back(i);
        }
    }
}

void solve()
{
    ll n, k;
    cin >> n >> k;

    vll v(n);
    for (auto &x : v)
        cin >> x;

    vll dp(n + 1, 0);
    for (int i = k + 1; i <= n; ++i)
    {
        dp[i] = 1e18;
        for (auto p : prime[i])
        {
            dp[i] = min(dp[i], 1LL + p * dp[i / p]);
        }
    }

    ll ops = 0;
    for (auto x : v)
        ops += dp[x];
        
    cout << ops << endl;
}

int main()
{
    fast_io();

    int t = 1;
    cin >> t;

    precompute();

    while (t--)
    {
        solve();
    }

    return 0;
}