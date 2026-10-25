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

    if ((n * (n + 1) >> 1) & 1)
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    cout << (n >> 1) << endl;
    int i;
    if (n & 1)
    {
        i = 3;
        while (i < n)
        {
            cout << i << " " << i + 1 << " ";
            i += 4;
        }
    }
    else
    {
        cout << 1 << " ";
        i = 4;
        while (i < n)
        {
            cout << i << " " << i + 1 << " ";
            i += 4;
        }
    }
    cout << i << endl;

    cout << (((n + 1) >> 1)) << endl;
    if (n & 1)
    {
        i = 1;
        while (i < n)
        {
            cout << i << " " << i + 1 << " ";
            i += 4;
        }
    }
    else
    {
        i = 2;
        while (i < n)
        {
            cout << i << " " << i + 1 << " ";
            i += 4;
        }
    }
    cout << endl;
}

int main()
{
    fast_io();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}