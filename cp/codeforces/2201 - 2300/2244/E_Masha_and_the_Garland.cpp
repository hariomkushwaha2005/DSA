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

void solve()
{
    // Your logic goes here
    ll n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    for (int i = 0; i < n; ++i)
    {
        if (i & 1)
        {
            if (s[i] == '1')
                s[i] = '0';
            else
                s[i] = '1';
        }
    }

    vll a(n + 1), b(n + 1), c(n + 1), d(n + 1);
    b[0] = 0;
    d[0] = 0;

    if (s[0] == '0')
    {
        a[0] = 1;
        c[0] = 0;
    }
    else
    {
        c[0] = 1;
        a[0] = 0;
    }

    for (int i = 1; i < n; ++i)
    {
        a[i] = a[i - 1];
        d[i] = d[i - 1];
        if (s[i] == '0' && s[i - 1] == '1')
        {
            a[i]++;
            d[i]++;
        }

        b[i] = b[i - 1];
        c[i] = c[i - 1];
        if (s[i] == '1' && s[i - 1] == '0')
        {
            b[i]++;
            c[i]++;
        }
    }

    while (q--)
    {
        ll l, r, k;
        cin >> l >> r >> k;
        
        l--;
        r--;

        int cur = min(a[r] - b[l], c[r] - d[l]);
        if(cur <= k) cout << "YES" << endl;
        else cout << "NO" << endl;
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