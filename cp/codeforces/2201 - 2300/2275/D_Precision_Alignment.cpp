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
    ll n, k;
    cin >> n >> k;

    vector<vll> v(n, vll(5, 0));

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i][1] >> v[i][2] >> v[i][3];
        v[i][0] = v[i][1] + v[i][2] + v[i][3];
        ll a = v[i][2] - v[i][3];
        ll b = v[i][1] - v[i][3];
        ll c = v[i][1] - v[i][2];
        if (a == 0 && b == 0)
            v[i][4] = -1;
        else if (a > 0 || b > 0 || c > 0)
            v[i][4] = 0;
        else
            v[i][4] = -2 * (max(c, max(a, b)) - 1);
    }

    ranges::sort(v);
    for (int i = 0; i < n - 1; ++i)
    {
        if (v[i][4] == -1 || v[i][4] > k)
        {
            cout << v[i][0] << endl;
            return;
        }

        k -= v[i][4];
        ll e = (v[i + 1][0] - v[i][0]);
        if ((i + 1) * e <= k)
            k -= e * (i + 1);
        else
        {
            ll f = (k / (i + 1));
            cout << v[i][0] + f << endl;
            return;
        }
    }
    if (v[n - 1][4] == -1 || v[n - 1][4] > k)
    {
        cout << v[n - 1][0] << endl;
        return;
    }
    k -= v[n - 1][4];
    ll f = k / n;
    cout << v[n - 1][0] + f << endl;
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