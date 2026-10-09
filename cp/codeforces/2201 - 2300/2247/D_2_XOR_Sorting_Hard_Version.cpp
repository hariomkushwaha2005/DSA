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

ll inf = 1e18;

class seg
{
    vll maxx;
    vll minn;
    vll bad;
    ll lvl;
    ll off;

public:
    seg(ll n)
    {
        ll x = 1;
        lvl = 0;
        while (x < n)
        {
            x <<= 1;
            lvl++;
        }
        off = x - 1;
        x <<= 1;
        minn.resize(x, inf);
        maxx.resize(x, -inf);
        bad.resize(lvl, 0);
    }
    void insert(ll i, ll val)
    {
        ll idx = off + i;

        ll curr = idx;
        ll curl = 0;
        while (curr > 0)
        {
            ll par = (curr - 1) >> 1;
            ll lc = (par << 1) + 1;
            ll rc = (par << 1) + 2;
            if (maxx[lc] > minn[rc])
                bad[curl]--;
            curr = par;
            curl++;
        }
        minn[idx] = val;
        maxx[idx] = val;

        curr = idx;
        curl = 0;
        while (curr > 0)
        {
            ll par = (curr - 1) >> 1;
            ll lc = (par << 1) + 1;
            ll rc = (par << 1) + 2;

            minn[par] = min(minn[lc], minn[rc]);
            maxx[par] = max(maxx[lc], maxx[rc]);
            if (maxx[lc] > minn[rc])
                bad[curl]++;
            curr = par;
            curl++;
        }
    }

    ll find()
    {
        for (int i = lvl - 1; i >= 0; --i)
        {
            if (bad[i] > 0)
                return 1LL << i;
        }
        return 0;
    }
};

void solve()
{
    ll n, q;
    cin >> n >> q;

    seg s(n);
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        s.insert(i, x);
    }
    cout << s.find() << endl;
    while (q--)
    {
        ll i, x;
        cin >> i >> x;

        s.insert(i, x);
        cout << s.find() << endl;
    }
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