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
    vll a(8, 0);
    ll ans = 0;
    ll cnt = -1;
    for (auto &x : v)
    {
        cin >> x;

        ll ops = 0;
        while (x != 1 && x != 4)
        {
            ll z = 0;
            while (x > 0)
            {
                ll ld = x % 10;
                x /= 10;
                z += ld * ld;
            }
            x = z;
            ops++;
        }
        if (x == 1)
        {
            cnt++;
            ans += cnt;
        }
        else
        {
            ops %= 8;
            a[ops]++;
        }
    }
    for (int i = 0; i < 8; ++i)
    {
        ans += (a[i] * (a[i] - 1)) / 2;
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