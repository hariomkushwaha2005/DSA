#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define endl '\n'
// #define all(x) (x).begin(), (x).end()

void solve()
{
    ll n;
    cin >> n;

    vector<array<ll, 3>> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }

    ranges::sort(v);

    ll g = 1;
    vll a(n);
    a[v[0][2]] = 1;
    ll end = v[0][1];
    for (int i = 1; i < n; ++i)
    {
        if (end < v[i][0])
            g = 2;
        a[v[i][2]] = g;
        end = max(end, v[i][1]);
    }
    if (g == 1)
        cout << -1 << endl;
    else
    {
        for (auto &i : a)
            cout << i << " ";
        cout << endl;
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