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

const ll mod = 998244353;
const ll maxn = 1000001;

ll fact[maxn], invfact[maxn];

ll power(ll base, ll exp)
{
    ll x = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            x = x * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return x;
}

ll modinv(ll n)
{
    return power(n, mod - 2);
}

void precompute()
{
    fact[0] = 1;
    for (int i = 1; i < maxn; ++i)
        fact[i] = fact[i - 1] * i % mod;

    invfact[maxn - 1] = modinv(fact[maxn - 1]);
    for (int i = maxn - 2; i >= 0; --i)
        invfact[i] = invfact[i + 1] * (i + 1) % mod;
}

ll ncr(ll n, ll r)
{
    return fact[n] * invfact[r] % mod * invfact[n - r] % mod;
}

void solve()
{
    ll n;
    cin >> n;

    string s;
    cin >> s;

    vll v;
    ll z = 0;

    for (int i = 1; i < n; ++i)
    {
        if (s[i] == s[i - 1])
            z++;
        else
        {
            v.push_back(z);
            z = 0;
        }
    }
    v.push_back(z);

    int e = 0, en = 0, o = 0, on = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (i & 1)
        {
            e += v[i];
            en++;
        }
        else
        {
            o += v[i];
            on++;
        }
    }

    ll x = 1, y = 1;
    if (en > 0)
        x = ncr(en + e - 1, en - 1);
    if (on > 0)
        y = ncr(on + o - 1, on - 1);

    ll ans = (x * y) % mod;
    cout << ans << endl;
}

int main()
{
    fast_io();
    precompute();

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}