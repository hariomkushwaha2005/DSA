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

    vector<array<ll, 3>> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }
    ranges::sort(v, [](const array<ll, 3> &a, const array<ll, 3> &b)
                 {
        if (a[0] != b[0]) 
            return a[0] < b[0];
        return a[1] > b[1]; });

    ll j = 0;
    for (int i = 1; i < n; ++i)
    {
        if (v[i][1] <= v[j][1])
        {
            cout << v[i][2] + 1 << " " << v[j][2] + 1;
            return;
        }
        else
            j = i;
    }
    cout << -1 << " " << -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}