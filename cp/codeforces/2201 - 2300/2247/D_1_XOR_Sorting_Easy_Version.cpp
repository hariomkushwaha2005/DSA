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
    ll off;
    ll z;

public:
    seg(ll n)
    {
        ll x = 1;
        while (x < n)
            x <<= 1;
        off = x - 1;
        x <<= 1;
        minn.resize(x, inf);
        maxx.resize(x, -inf);
        z = x;
    }
    void update(ll idx)
    {
        while (idx > 0)
        {
            idx = (idx - 1) >> 1;
            minn[idx] = min(minn[(idx << 1) + 1], minn[(idx << 1) + 2]);
            maxx[idx] = max(maxx[(idx << 1) + 1], maxx[(idx << 1) + 2]);
        }
    }
    void insert(ll i, ll val)
    {
        ll idx = off + i;
        minn[idx] = val;
        maxx[idx] = val;
        update(idx);
    }

    ll find()
    {
        ll st = 0, size = 1;
        while (size <= off + 1)
        {
            ll lim = st + size - 1;
            for (int i = st; i < lim && i < z - 1; ++i)
            {
                if (maxx[i] > minn[i + 1])
                    return (off + 1)/size;
            }
            st += size;
            size <<= 1;
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