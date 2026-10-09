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
    for (auto &x : v)
        cin >> x;

    vll a(n, 0);
    vll b(n, 0);
    ll tot = 0;
    ll one = 0, zero = 0;
    for (int i = 0; i < n; ++i)
    {
        if (v[i] == 1)
            ++one;
        else
        {
            a[i] = one;
            tot += one;
        }

        if (v[n - 1 - i] == 0)
            ++zero;
        else
            b[n - 1 - i] = zero;
    }

    string s;
    cin >> s;

    cout << tot << " ";
    ll l = 0, r = n - 1;
    ll exone = 0, exzero = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '1')
        {
            while (l < r && v[l] == 0)
                ++l;
            if (l < r)
            {
                tot -= (b[l] - exzero);
                exone++;
            }
            ++l;
        }
        else
        {
            while (l < r && v[r] == 1)
                --r;
            if (l < r)
            {
                tot -= (a[r] - exone);
                exzero++;
            }
            --r;
        }
        cout << tot << " ";
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