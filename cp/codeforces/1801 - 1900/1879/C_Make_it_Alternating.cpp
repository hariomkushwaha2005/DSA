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
int mod = 998244353;
ll fact[200001];
void facto()
{
    fact[0] = 1;
    for (int i = 1; i < 200001; ++i)
    {
        fact[i] = fact[i - 1] * i % mod;
    }
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();

    ll ans = 1;
    int cnt = 0;
    int blocksize = 1;
    for (int i = 1; i < n; ++i)
    {
        if (s[i] == s[i - 1])
            blocksize++;
        else
        {
            if (blocksize > 1)
            {
                cnt += blocksize - 1;
                ans = ans * blocksize % mod;
            }
            blocksize = 1;
        }
    }
    if (blocksize > 1)
    {
        cnt += blocksize - 1;
        ans = ans * blocksize % mod;
    }

    ans = ans * fact[cnt] % mod;
    cout << cnt << " " << ans << endl;
}

int main()
{
    fast_io();

    int t = 1;
    cin >> t;
    facto();
    while (t--)
    {
        solve();
    }

    return 0;
}