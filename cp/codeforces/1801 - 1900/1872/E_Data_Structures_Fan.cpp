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

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve()
{
    ll n;
    cin >> n;

    vll v(n);
    for (auto &i : v)
        cin >> i;

    string s;
    cin >> s;

    vll pre(n + 1, 0);
    ll zxor = 0;

    for (int i = 0; i < n; ++i)
    {
        pre[i + 1] = pre[i] ^ v[i];
        if (s[i] == '0')
            zxor ^= v[i];
    }

    ll q;
    cin >> q;
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 2)
        {
            ll a;
            cin >> a;
            if (a)
                cout << (pre[n] ^ zxor) << " ";
            else
                cout << zxor << " ";
        }
        else
        {
            ll a, b;
            cin >> a >> b;
            --a;
            zxor ^= (pre[b] ^ pre[a]);
        }
    }
    cout << endl;
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