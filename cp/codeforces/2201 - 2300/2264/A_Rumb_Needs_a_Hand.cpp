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

    ll last = n + 1;
    bool res = 1;
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;

        if (x != i + 1)
        {
            if (x > last)
                res = 0;
            last = x;
        }
    }

    if (res)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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