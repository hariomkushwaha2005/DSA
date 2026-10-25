#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

void solve()
{
    ll n;
    cin >> n;

    ll xorr = 0;
    vll v(n);
    for (auto &i : v)
    {
        cin >> i;
        xorr ^= i;
    }

    if (xorr == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        ll i = 0;
        ll xorrr = 0;
        while (i < n && xorrr != xorr)
            xorrr ^= v[i++];

        while (i < n && xorrr != 0)
            xorrr ^= v[i++];

        if (i == n)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}