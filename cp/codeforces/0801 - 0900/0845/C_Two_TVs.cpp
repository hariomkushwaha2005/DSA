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

    vector<array<ll, 2>> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i][0] >> v[i][1];

    ranges::sort(v);
    ll last1 = -1, last2 = -1;
    for (int i = 0; i < n; ++i)
    {
        if (v[i][0] > last1)
            last1 = v[i][1];
        else if (v[i][0] > last2)
            last2 = v[i][1];
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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