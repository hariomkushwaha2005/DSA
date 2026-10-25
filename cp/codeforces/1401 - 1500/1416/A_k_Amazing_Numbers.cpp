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

    vll v(n + 1);
    vll last(n + 1, 0);
    vll maxx(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        maxx[v[i]] = max(maxx[v[i]], i - last[v[i]]);
        last[v[i]] = i;
    }

    vll a(n + 1, 1e9);
    for (ll i = 1; i <= n; ++i)
    {
        if (last[i] != 0)
        {
            maxx[i] = max(maxx[i], n + 1 - last[i]);
            a[maxx[i]] = min(a[maxx[i]], i);
        }
    }

    cout << (a[1] == 1e9 ? -1 : a[1]) << " ";
    for (int i = 2; i <= n; ++i)
    {
        a[i] = min(a[i], a[i - 1]);
        cout << (a[i] == 1e9 ? -1 : a[i]) << " ";
    }

    cout << endl;
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