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

    vll a;
    vll b;
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;

        if (i & 1)
            b.push_back(x);
        else
            a.push_back(x);
    }

    ranges::sort(a);
    ranges::sort(b);

    ll c = ((n + 1) >> 1);
    ll d = (n >> 1);

    int i = 0, j = 0;
    while (i < c && j < d)
    {
        while (i < c && j < d && b[j] < a[i])
            ++j;

        if (i < c)
            a[i] = 0;

        while (i < c && j < d && a[i] < b[j])
            ++i;

        if (j < d)
            b[j] = 0;
    }

    bool end = 0;
    if (c == d)
        end = 1;
    i = 0, j = 0;

    if (end)
    {
        while (j < d && b[j] == 0)
            ++j;

        while (i < c && j < d)
        {
            while (i < c && j < d && a[i] < b[j])
                ++i;

            if (j < d)
                b[j] = 0;

            while (i < c && j < d && b[j] < a[i])
                ++j;

            if (i < c)
                a[i] = 0;
        }
    }
    else
    {
        while (i < c && a[i] == 0)
            ++i;

        while (i < c && j < d)
        {
            while (i < c && j < d && b[j] < a[i])
                ++j;

            if (i < c)
                a[i] = 0;

            while (i < c && j < d && a[i] < b[j])
                ++i;

            if (j < d)
                b[j] = 0;
        }
    }

    if (i < c)
        a[i] = 0;
    else
        b[j] = 0;

    ll sum = 0;
    for (auto e : a)
        sum += e;
    for (auto e : b)
        sum += e;

    if (sum > 0)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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