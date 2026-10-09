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

    vll a(101, 0);
    for (auto x : v)
        a[x]++;

    bool b = 1;
    while (b)
    {
        b = 0;
        for (int i = 100; i > 0; --i)
        {
            if (a[i] > 0)
            {
                a[i]--;
                cout << i << " ";
                if (a[i] > 0)
                    b = 1;
            }
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