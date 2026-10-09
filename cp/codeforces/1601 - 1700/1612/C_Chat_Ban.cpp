#pragma GCC optimize("O3,unroll-loops")

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

void solve()
{
    ll k, x;
    cin >> k >> x;

    ll z = (k * (k + 1) >> 1);

    if(k * k <= x){
        cout << 2*k - 1<< endl;
        return;
    }


    if (x <= z)
    {
        ll l = 1, h = k;
        while (l <= h)
        {
            ll mid = l + ((h - l) >> 1);
            ll val = (mid * (mid + 1) >> 1);
            if (val < x)
            {
                l = mid + 1;
            }
            else
                h = mid - 1;
        }
        cout << l << endl;
    }
    else
    {
        x -= z;
        ll l = 1, h = k - 1;
        while (l <= h)
        {
            ll mid = l + ((h - l) >> 1);
            ll val = k * mid - (mid * (mid + 1) >> 1);
            if (val < x)
            {
                l = mid + 1;
            }
            else
                h = mid - 1;
        }
        cout << k + l << endl;
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