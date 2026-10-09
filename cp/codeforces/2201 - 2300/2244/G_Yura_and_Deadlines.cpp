#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

inline void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

class fw
{
public:
    int n;
    vll a;

    fw(int n) : n(n), a(n + 1, 0) {};

    void put(int i, ll val)
    {
        for (; i <= n; i += (i & -i))
        {
            a[i] = max(a[i], val);
        }
    }

    ll get(int i)
    {
        ll val = 0;
        for (; i > 0; i -= (i & -i))
        {
            val = max(val, a[i]);
        }
        return val;
    }
};

void solve()
{
    ll n;
    cin >> n;

    vll a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<vi> b(n + 1);

    vll dp(n + 1, 0);

    fw f(n);

    ll ans = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (auto it : b[i])
        {
            f.put(it, dp[it]);
        }
        ll ind = i + a[i] + 1;
        if (ind <= n)
            b[ind].push_back(i);

        dp[i] = a[i];

        ll idx = i - a[i] - 1;
        if (idx > 0)
            dp[i] = max(dp[i], a[i] + f.get(idx));

        ans = max(ans, dp[i]);
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