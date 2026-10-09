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
    ll n;
    cin >> n;

    vll v(31, 0);
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;

        ll a = 1;
        while (a <= x)
        {
            if (a & x)
                v[31 - __builtin_clz(a)]++;

            a <<= 1;
        }
    }

    ll val = 0;
    for (auto i : v)
        val = __gcd(val, i);

    if(val == 0){
        for(int i = 1; i <= n; ++i) cout << i << " ";
        cout << endl;
        return;
    }

    vll ans;

    for (int i = 1; i * i <= val; ++i)
    {
        if (val % i == 0)
        {
            ans.push_back(i);
            if (i != val / i)
                ans.push_back(val / i);
        }
    }

    sort(all(ans));

    for (auto c : ans)
        cout << c << " ";
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