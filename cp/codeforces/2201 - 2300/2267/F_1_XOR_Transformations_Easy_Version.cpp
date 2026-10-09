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
    ll n, q;
    cin >> n >> q;

    vll v(n);
    for (auto &x : v)
        cin >> x;

    ranges::sort(v);

    vector<vll> dav;
    dav.push_back(v);

    bool allz = (v.back() == 0);

    vll a;
    a.reserve(n * (n - 1) / 2);

    while (!allz)
    {
        a.clear();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                a.push_back(v[i] ^ v[j]);
            }
        }
        nth_element(a.begin(), a.begin() + n, a.end());
        a.resize(n);
        v = a;
        ranges::sort(v);
        dav.push_back(v);

        allz = (v.back() == 0);
    }

    while (q--)
    {
        ll x;
        cin >> x;

        if (x >= dav.size())
            cout << 0 << endl;
        else
            cout << dav[x].back() - dav[x].front() << endl;
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