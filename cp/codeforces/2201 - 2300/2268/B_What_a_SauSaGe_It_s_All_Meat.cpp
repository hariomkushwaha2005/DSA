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

    ll f = 0, t = 0;
    for (int i = 0; i < n; ++i)
    {
        if (v[i] % 3 == 0)
            t++;
        else if (v[i] % 5 == 0)
            f++;
    }

    cout << t + f << " ";
    while (q--)
    {
        ll a, b;
        cin >> a >> b;

        --a;
        if (v[a] % 3 == 0)
            t--;
        else if (v[a] % 5 == 0)
            f--;
        v[a] = b;
        if (v[a] % 3 == 0)
            t++;
        else if (v[a] % 5 == 0)
            f++;

        cout << t + f << " ";
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