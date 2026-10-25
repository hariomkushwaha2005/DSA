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

ll mod = 1e9 + 7;
ll maxn = 40000;

vll pals;
void findPals()
{
    for (int i = 1; i <= maxn; ++i)
    {
        ll n = i;
        ll rn = 0;
        while (n > 0)
        {
            ll ld = n % 10;
            rn = rn * 10 + ld;
            n /= 10;
        }
        if (i == rn)
            pals.push_back(i);
    }
}

ll preCom(ll i, ll val, vector<vll> &dp)
{
    if (val == 0)
        return 1;
    if (val < 0)
        return 0;
    if (i >= (ll)pals.size())
        return 0;
    if (dp[i][val] != -1)
        return dp[i][val];

    return dp[i][val] = (preCom(i, val - pals[i], dp) + preCom(i + 1, val, dp)) % mod;
}

void solve(vector<vll> &dp)
{
    ll n;
    cin >> n;

    cout << dp[0][n] << endl;
}

int main()
{
    fast_io();

    findPals();
    vector<vll> dp(pals.size(), vll(40001, -1));
    for (int i = 1; i <= 40000; ++i)
        preCom(0, i, dp);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve(dp);
    }

    return 0;
}