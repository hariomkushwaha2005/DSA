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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() ^
               (uint64_t)(new char)^__builtin_ia32_rdtsc());

map<ll, ll> chash;

ll getHash(ll x)
{
    if (!chash.count(x))
    {
        ll rnd = rng();
        rnd += 0x9e3779b97f4a7c15;
        rnd = (rnd ^ (rnd >> 30)) * 0xbf58476d1ce4e5b9;
        rnd = (rnd ^ (rnd >> 27)) * 0x94d049bb133111eb;
        rnd ^= (rnd >> 31);
        chash[x] = rnd;
    }
    return chash[x];
}

void solve()
{
    ll n;
    cin >> n;

    vll v(n);
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;

        ll a = 0;
        while (!(x & 1))
        {
            x >>= 1;
            a ^= getHash(2);
        }
        for (int j = 3; j * j <= x; j += 2)
        {
            if (x % j == 0)
            {
                while (x % j == 0)
                {
                    x /= j;
                    a ^= getHash(j);
                }
            }
        }
        if (x > 1)
            a ^= getHash(x);

        v[i] = a;
    }

    vll pv(n);
    pv[0] = v[0];
    for (int i = 1; i < n; ++i)
        pv[i] = v[i] ^ pv[i - 1];

    map<ll, ll> f;
    for (auto i : pv)
        f[i]++;

    ll ans = 0;
    for (auto i : v)
        ans += f[i];

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