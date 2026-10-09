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

    ll z = 0;
    vll v(n);
    for (auto &x : v)
    {
        cin >> x;
        if (x == 0)
            z++;
    }
    string s(n, 'C');
    if (z == 0)
    {
        cout << "YES" << endl;
        cout << s << endl;
    }
    else if (z == 1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        int i = 0;
        while (v[i] != 0)
            ++i;
        s[i++] = 'A';
        for (; i < n; ++i)
            if (v[i] == 0)
                s[i] = 'B';
        cout << s << endl;
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